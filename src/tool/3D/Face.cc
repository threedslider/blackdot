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
#include "Face.hpp"
#include <iostream>

namespace Blackdot
{

	void Face::ComputeNormal(Vertex* v1, Vertex* v2, Vertex* v3)
	{
		float a[3]; float b[3]; float result[3];
		float length;

		a[0] = v1->position.X() - v2->position.X();
		a[1] = v1->position.Y() - v2->position.Y();
		a[2] = v1->position.Z() - v2->position.Z();

		b[0] = v2->position.X() - v3->position.X();
		b[1] = v2->position.X() - v3->position.X();
		b[2] = v2->position.X() - v3->position.X();


		result[0] = a[1] * b[2] - b[1] * a[2];
		result[1] = b[0] * a[2] - a[0] * b[2];
		result[2] = a[0] * b[1] - b[0] * a[1];


		length = (float)sqrt(result[0] * result[0] + result[1] * result[1] + result[2] * result[2]);

		if (length == 0.0f) length = 1.0f;
		result[0] /= length;
		result[1] /= length;
		result[2] /= length;

		glNormal3fv(result);
	}

}



