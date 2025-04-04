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

/*
  Vertex.hpp

  
  April 3 2025 
*/


#ifndef __Vertex_hpp
#define __Vertex_hpp


#include "../Vector.hpp"
#include <list>

namespace Blackdot
{

  class Vertex {
    public:
        int id;        
        bool	IsSelect;
        Vector<float> position;
    
        
        Vertex(int id, float x = 0.0f, float y = 0.0f, float z = 0.0f)
            : id(id), position(x, y, z), IsSelect(false) {}
    
        void print() {
            printf("Vertex ID %d: ", id);
            position.print();
        }
    };

    typedef list<Vertex*>				_pVertex;
    typedef list<Vertex*>::iterator		_iVertex;

}
#endif


