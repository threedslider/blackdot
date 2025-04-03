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

#ifndef Face_hpp
#define Face_hpp

#include "Vertex.hpp"
#include "Edge.hpp"
#include <vector>

namespace Blackdot
{

  class Face {
    public:
        int id;                 // ID unique de la face
        std::vector<Edge> edges; // Liste des arêtes de la face
    
        // Constructeur
        Face(int id) : id(id) {}
    
        // Ajouter une arête à la face
        void addEdge(const Edge& edge) {
            edges.push_back(edge);
        }
    
        // Affichage de la face avec ses edges
        void print(std::vector<Vertex>& vertices)  {
            printf("Face ID %d: \n", id);
            for ( auto& edge : edges) {
                edge.print(vertices);
            }
        }
    };

}
#endif


