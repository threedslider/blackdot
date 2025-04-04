/* 
This file is part of Blackdot
Copyright (C) 2024-2025 Laurent Le Flem

This program is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software Foundation, 
either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. 
If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef _OBJECTSYSTEM_H
#define _OBJECTSYSTEM_H

#include "Object.hpp"
#include "tool/3D/Vertex.hpp"
#include "gui_xsi/graphic/Mouse.hpp"
#include "gui_xsi/graphic/Viewport.hpp"

namespace Blackdot
{

    class ObjectSystem
    {
        int		cmpFace;
        int		tmpFace[3];

        _iVertex	iVertex;
        _iFace		iFace;
    public:
        Object obj;


        ObjectSystem();
        ~ObjectSystem();

        //vertex-------------------------------------------
        void	AddVertex(Mouse *mouse, Viewport *v);
        void	SelectVertex(Mouse *mouse, Viewport *v);
        void	TranslateVertex(Mouse *mouse, Viewport *v);


        void	SelectRectVertex(Mouse *mouse, Viewport *v);
        void	SelectAllVertex();
        void	DeSelectAllVertex();

        void	DeleteVertexSelect();
        void	DeleteAllVertex();

        //face---------------------------------------------
        void	AddFace(Mouse *mouse, Viewport *v);
        Vertex*	GetVertex(int id);

        void	CancelFace();
        void	DeleteFace();

        //-------------------------------------------------
        void	Draw();
    };

}


#endif
