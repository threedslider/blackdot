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
  Face.hpp

  April 3 2025 
*/

#ifndef __Face_hpp
#define __Face_hpp

#include "Vertex.hpp"
#include "Edge.hpp"
#include <vector>

namespace Blackdot
{

  class Face {
    public:
        int id;     
        Vertex* a;
        Vertex* b;
        Vertex* c;
        std::vector<Edge> edges; 
    
        
        Face(int id, Vertex* a, Vertex* b, Vertex* c ) : id(id), a(a), b(b), c(c)  {}
    
        
        void addEdge(const Edge& edge) {
            edges.push_back(edge);
        }
    
        
        void print(std::vector<Vertex>& vertices)  {
            printf("Face ID %d: \n", id);
            for ( auto& edge : edges) {
                edge.print(vertices);
            }
        }

        void ComputeNormal(Vertex* v1, Vertex* v2, Vertex* v3);

    };

    typedef list<Face*>				_pFace;
    typedef list<Face*>::iterator	_iFace;

}
#endif


