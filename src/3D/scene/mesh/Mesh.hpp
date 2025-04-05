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
  Mesh.hpp

  April 3 2025 
*/


#ifndef __Mesh_hpp
#define __Mesh_hpp

#include "tool/3D/Vertex.hpp"
#include "tool/3D/Edge.hpp"
#include "tool/3D/Face.hpp"
#include "tool/Vector.hpp"
#include <vector>

namespace Blackdot
{

    class Mesh {
        public:
            std::vector<Vertex> vertices;  
            std::vector<Edge> edges;       
            std::vector<Face> faces;       
        
           
            void addVertex(float x, float y, float z) {
                int id = vertices.size() + 1;  
                vertices.push_back(Vertex(id, x, y, z));
            }
        
            
            void addEdge(int vertexIndex1, int vertexIndex2) {
                int id = edges.size() + 1;  
                edges.push_back(Edge(id, vertexIndex1, vertexIndex2));
            }
        
           
            /*void addFace(const std::vector<int>& edgeIndices) {
                int id = faces.size() + 1;  
                Face face(id);
                for (int edgeIndex : edgeIndices) {
                    face.addEdge(edges[edgeIndex]);
                }
                faces.push_back(face);
            }*/
        
            
            void print() {
                printf("Mesh:\n");
                for ( auto& face : faces) {
                    face.print(vertices);
                }
            }

            void DrawAxes();

        };
}

#endif
