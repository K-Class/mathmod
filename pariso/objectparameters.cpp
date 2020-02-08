/***************************************************************************
 *   Copyright (C) 2020by Abderrahman Taha                                *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor,Boston, MA 02110-1301 USA             *
 ***************************************************************************/
#include "objectparameters.h"

MasterThread::MasterThread() {}
MasterThread::~MasterThread() {}
WorkerThread::WorkerThread() {}
WorkerThread::~WorkerThread() {}
ParisoObject::ParisoObject() {}
ParisoObject::~ParisoObject() {}
///+++++++++++++++++++++++++++++++++++++++++
uint ParisoObject::CNDtoUse(uint index, struct ComponentInfos *components)
{
    uint idx = 0;
    for (uint i = 0; i < components->NbComponents.size() - 1; i++)
        idx += components->NbComponents[i];
    for (uint fctnb = 0;
            fctnb < (components->NbComponents[components->NbComponents.size() - 1]);
            fctnb++)
        if (index <= components->ParisoVertex[2 * (fctnb + idx) + 1] &&
                index >= components->ParisoVertex[2 * (fctnb + idx)])
            return fctnb;
    return 30;
}

//+++++++++++++++++++++++++++++++++++++++++
void ParisoObject::clear(struct ComponentInfos *cp)
{
    cp->ParisoTriangle.clear();
    cp->ParisoVertex.clear();
    cp->NbComponents.clear();
    cp->ThereisCND.clear();
    cp->ParisoCondition.clear();
    cp->ThereisRGBA.clear();

    cp->NbTrianglesVerifyCND.clear();
    cp->NbTrianglesNoCND.clear();
    cp->NbTrianglesNotVerifyCND.clear();
    cp->NbTrianglesBorderCND.clear();

    cp->ParisoCurrentComponentIndex = 0;
    cp->ParisoNbComponents = 0;
    cp->Interleave = true;
    cp->pariso = false;
    cp->updateviewer = false;
}

ObjectParameters::ObjectParameters()
{
    objectproperties.infosdetails[0] = objectproperties.infosdetails[1] =
                                           objectproperties.infosdetails[2] = 1;
    objectproperties.boundingbox = -1;
    objectproperties.triangles = -1;
    objectproperties.typedrawing = 1;
    objectproperties.smoothline = -1;
    objectproperties.anim = -1;
    objectproperties.animx = -1;
    objectproperties.animy = -1;
    objectproperties.animz = -1;
    objectproperties.animxyz = 1;
    objectproperties.animxValue = objectproperties.animyValue =
                                      objectproperties.animzValue = 0.0;
    objectproperties.animxValueStep = objectproperties.animyValueStep =
                                          objectproperties.animzValueStep = 0.0;
    objectproperties.slider = -1;
    objectproperties.morph = -1;
    objectproperties.morphstep = -1;
    objectproperties.norm = -1;
    objectproperties.plan = 1;
    objectproperties.transparency = -1;
    objectproperties.png_ok = 1;
    objectproperties.jpg_ok = objectproperties.bmp_ok = -1;
    objectproperties.quality_image = 50;
    objectproperties.colortype = 0;
    objectproperties.colortypeParam = 0;
}
