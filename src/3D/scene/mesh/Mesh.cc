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

#include <GLFW/glfw3.h>
#include "Mesh.hpp"
#include <iostream>

namespace Blackdot
{

	void Mesh::DrawAxes()
	{
		glPushMatrix();
		//		glDisable(GL_LIGHTING);

		glBegin(GL_LINE_STRIP);
		glColor3ub(255, 0, 0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(10.0, 0.0, 0.0);
		glVertex3f(7.5, 2.5, 0.0);
		glVertex3f(7.5, -2.5, 0.0);
		glVertex3f(10.0, 0.0, 0.0);
		glVertex3f(10.0, 0.0, 0.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 10.0, 0.0);
		glVertex3f(0.0, 10.0, 0.0);
		glVertex3f(2.5, 7.5, 0.0);
		glVertex3f(-2.5, 7.5, 0.0);
		glVertex3f(0.0, 10.0, 0.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 10.0);
		glVertex3f(2.5, 0.0, 7.5);
		glVertex3f(-2.5, 0.0, 7.5);
		glVertex3f(0.0, 0.0, 10.0);
		glVertex3f(0.0, 0.0, 10.0);
		glEnd();

		glPopMatrix();
	}

}


