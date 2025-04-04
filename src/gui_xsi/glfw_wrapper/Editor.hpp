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



#ifndef __Editor_hpp
#define __Editor_hpp

#include <GLFW/glfw3.h>
#include "graphic/ViewportSystem.hpp"
#include "3D/scene/object/ObjectSystem.hpp"
#include "3D/scene/mesh/Mesh.hpp"

namespace Blackdot
{

    void	mouseButtonCallback(GLFWwindow* Window, int button, int action, int mods);

    class Editor
    {
        Mouse	mouse;
        ViewportSystem	vs;
        ObjectSystem	objectsystem;
        Mesh mesh;

        int		Width, Height;

        GLFWwindow* window;

    public:
        Editor();
        ~Editor();

        void	InitGL(int w, int h, char* title);   
        
        void    Mouse(int x, int y);        
        
        void	Key(unsigned char key, int x, int y);
        void	KeySpec(int key, int x, int y);

        void    Reshape(int w, int h);

        void	Draw();
        void	DrawScene();

        void	ResetMouse();
            
        //void	String(int x, int y, char *s, ...);
    };

}

#endif
