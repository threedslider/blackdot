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
Main program

Laurent Le Flem

August 06 2024 (My great day !)
*/

#include "gui_xsi/graphic/InitGL.hpp"
#include "tool/Vector.hpp"
#include "tool/3D/Vertex.hpp"
#include "tool/3D/Edge.hpp"
#include "tool/3D/Face.hpp"
#include "3D/scene/mesh/Mesh.hpp"

using namespace Blackdot;

int main() {
    
    Mesh mesh;

    
    mesh.addVertex(-1.0f, -1.0f, -1.0f);  // Vertex 1
    mesh.addVertex( 1.0f, -1.0f, -1.0f);  // Vertex 2
    mesh.addVertex( 1.0f,  1.0f, -1.0f);  // Vertex 3
    mesh.addVertex(-1.0f,  1.0f, -1.0f);  // Vertex 4
    mesh.addVertex(-1.0f, -1.0f,  1.0f);  // Vertex 5
    mesh.addVertex( 1.0f, -1.0f,  1.0f);  // Vertex 6
    mesh.addVertex( 1.0f,  1.0f,  1.0f);  // Vertex 7
    mesh.addVertex(-1.0f,  1.0f,  1.0f);  // Vertex 8

    
    mesh.addEdge(0, 1); // 1-2
    mesh.addEdge(1, 2); // 2-3
    mesh.addEdge(2, 3); // 3-4
    mesh.addEdge(3, 0); // 4-1
    mesh.addEdge(4, 5); // 5-6
    mesh.addEdge(5, 6); // 6-7
    mesh.addEdge(6, 7); // 7-8
    mesh.addEdge(7, 4); // 8-5
    mesh.addEdge(0, 4); // 1-5
    mesh.addEdge(1, 5); // 2-6
    mesh.addEdge(2, 6); // 3-7
    mesh.addEdge(3, 7); // 4-8

    
    mesh.addFace({0, 1, 2, 3}); // Face 1
    mesh.addFace({4, 5, 6, 7}); // Face 2
    mesh.addFace({0, 1, 5, 4}); // Face 3
    mesh.addFace({1, 2, 6, 5}); // Face 4
    mesh.addFace({2, 3, 7, 6}); // Face 5
    mesh.addFace({3, 0, 4, 7}); // Face 6

    
    mesh.print();

    return 0;
}