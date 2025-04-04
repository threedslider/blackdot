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
#include "Object.hpp"

namespace Blackdot
{

Object::Object()
{

}

Object::~Object()
{
	Clear();
}

void Object::Clear()
{
	for(iFace = pFace.begin();  iFace != pFace.end(); iFace++ )
		delete *iFace;
	pFace.clear();

	for(iVertex = pVertex.begin();  iVertex != pVertex.end(); iVertex++ )
		delete *iVertex;
	pVertex.clear();
}


void Object::DrawVertex()
{
	glBegin(GL_POINTS);
	for(iVertex = pVertex.begin();  iVertex != pVertex.end(); iVertex++ )
	{
		if((*iVertex)->IsSelect==true)	
			glColor3f(1,0,0);
		else							
			glColor3f(1,1,1);

		glVertex3f((*iVertex)->position.X(), (*iVertex)->position.Y(), (*iVertex)->position.Z());
	}
	glEnd();
}

void Object::DrawFace()
{
	glColor3f(0,0,0);
	glBegin(GL_TRIANGLES);

	for(iFace = pFace.begin();  iFace != pFace.end(); iFace++ )
	{
		(*iFace)->ComputeNormal((*iFace)->a, (*iFace)->b, (*iFace)->c);
		glVertex3f((*iFace)->a->position.X(), (*iFace)->a->position.Y(), (*iFace)->a->position.Z());
		glVertex3f((*iFace)->b->position.X(), (*iFace)->b->position.Y(), (*iFace)->b->position.Z());
		glVertex3f((*iFace)->c->position.X(), (*iFace)->c->position.Y(), (*iFace)->c->position.Z());
	}
	glEnd();
}

}
