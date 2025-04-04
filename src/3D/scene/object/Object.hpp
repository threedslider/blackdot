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


#ifndef __Object_hpp
#define __Object_hpp

#include "tool/3D/Vertex.hpp"
#include "tool/3D/Face.hpp"


namespace Blackdot
{

    class Object
    {
    public:
        _pVertex	pVertex;
        _iVertex	iVertex;

        _pFace		pFace;
        _iFace		iFace;

        Object();
        ~Object();

        void	Clear();

        void	DrawVertex();
        void	DrawFace();
    };

}

#endif//_OBJECT_H