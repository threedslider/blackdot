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
  Edge.hpp

  April 3 2025 
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include "Vertex.hpp"


namespace Blackdot
{

  class Edge {
    public:
        int id;        
        int vertexIndex1;  
        int vertexIndex2;  
    
        // Constructeur
        Edge(int id, int vertexIndex1, int vertexIndex2)
            : id(id), vertexIndex1(vertexIndex1), vertexIndex2(vertexIndex2) {}
    
        void print(std::vector<Vertex>& vertices) {
            printf("Edge ID %d: ", id);
            vertices[vertexIndex1].print();
            vertices[vertexIndex2].print();
        }
    };

}
#endif


