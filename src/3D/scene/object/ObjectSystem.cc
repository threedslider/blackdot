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


#include <Windows.h>
#include <gl/GLU.h>
#include <GLFW/glfw3.h>
#include "ObjectSystem.hpp"

namespace Blackdot
{

ObjectSystem::ObjectSystem()
{
	cmpFace=0;
	tmpFace[0] = tmpFace[1] = tmpFace[2] = 0;
}

ObjectSystem::~ObjectSystem()
{
}

void ObjectSystem::AddVertex(Mouse *mouse, Viewport *v)
{
	int id=0;

	if(obj.pVertex.size()!=0)
	{
		id=obj.pVertex.back()->id+1;
	}
	GLdouble	Pos[3];
	GLdouble	Tmp[3];

	gluProject(0,0,0, v->model, v->proj, v->viewport, &Tmp[0], &Tmp[1], &Tmp[2]);

	gluUnProject(mouse->x, mouse->y, Tmp[2], v->model, v->proj, v->viewport, &Pos[0], &Pos[1], &Pos[2]);

	obj.pVertex.push_back(new Vertex(id, Pos[0], Pos[1], Pos[2]));
}

void ObjectSystem::TranslateVertex(Mouse *mouse, Viewport *v)
{
	GLdouble wx, wy, wz;
	GLdouble _wx, _wy, _wz;
	GLdouble x, y, z;

	gluProject(0,0,0, v->model, v->proj, v->viewport, &x,&y,&z);

	gluUnProject ((GLdouble) mouse->x, (GLdouble) mouse->y, z, 	v->model, v->proj, v->viewport, &wx, &wy, &wz); 

	gluUnProject ((GLdouble) mouse->clicx, (GLdouble) mouse->clicy, z, v->model, v->proj, v->viewport, &_wx, &_wy, &_wz); 

	for(iVertex = obj.pVertex.begin();  iVertex != obj.pVertex.end(); iVertex++ )
	{
		if((*iVertex)->IsSelect==true)
		{
			(*iVertex)->position.set_plus_assign_equalX(wx - _wx);
			(*iVertex)->position.set_plus_assign_equalY(wy - _wy);
			(*iVertex)->position.set_plus_assign_equalZ(wz - _wz);
		}
	}
}

void ObjectSystem::SelectVertex(Mouse *mouse, Viewport *v)
{
	GLdouble zone=5;
	GLdouble _x, _y, _z;

	for(iVertex = obj.pVertex.begin();  iVertex != obj.pVertex.end(); iVertex++ )
	{
		gluProject((*iVertex)->position.X(), (*iVertex)->position.Y(), (*iVertex)->position.Z(), v->model, v->proj, v->viewport, &_x, &_y, &_z);
		
		if( _x < mouse->x+zone && _x > mouse->x-zone &&	_y < mouse->y+zone && _y > mouse->y-zone )
		{
			(*iVertex)->IsSelect=!(*iVertex)->IsSelect;
			return;
		}
	}
}

void ObjectSystem::SelectRectVertex(Mouse *mouse, Viewport *v)
{
	int x, y;
	int	px, py;

	if(mouse->x > mouse->posx)	
	{
		x=mouse->x;
		px=mouse->posx;
	}
	else
	{
		x=mouse->posx;
		px=mouse->x;
	}
	
	if(mouse->y > mouse->posy)
	{
		y=mouse->y;
		py=mouse->posy;
	}
	else 
	{
		y=mouse->posy;
		py=mouse->y;
	}

	GLdouble wx, wy, wz;

	for(iVertex = obj.pVertex.begin();  iVertex != obj.pVertex.end(); iVertex++ )
	{
		if((*iVertex)->IsSelect!=true)
		{
            gluProject ((*iVertex)->position.X(), (*iVertex)->position.Y(), (*iVertex)->position.Z(),v->model, v->proj, v->viewport, &wx, &wy, &wz);
		
			if(	wx > px && wx < x && wy > py && wy < y )
				(*iVertex)->IsSelect=true;
		}
	}
}

void ObjectSystem::SelectAllVertex()
{
	for(iVertex = obj.pVertex.begin();  iVertex != obj.pVertex.end(); iVertex++ )
		(*iVertex)->IsSelect=true;
}

void ObjectSystem::DeSelectAllVertex()
{
	for(iVertex = obj.pVertex.begin();  iVertex != obj.pVertex.end(); iVertex++ )
		(*iVertex)->IsSelect=false;
}

void ObjectSystem::DeleteVertexSelect()
{
	CancelFace();
	DeleteFace();

	_iVertex i	 = obj.pVertex.begin();
	_iVertex iEnd= obj.pVertex.end();

	for(; i != iEnd;)
	{
		if((*i)->IsSelect==true)
		{
			Vertex *p=(*i);
			++i;
			obj.pVertex.remove(p);
			delete p;
			continue;
		}
		++i;
	}
}

void ObjectSystem::DeleteAllVertex()
{
	CancelFace();
	obj.Clear();
}


void ObjectSystem::Draw()
{
	glColor3f(0,0,0);
	obj.DrawFace();
	glDisable(GL_LIGHTING);

	glPointSize(3);
	obj.DrawVertex();
	glPointSize(1);
}


void ObjectSystem::AddFace(Mouse *mouse, Viewport *v)
{
	int zone=5;
	GLdouble _x, _y, _z;
	int Faceid = 0;
	
	for(iVertex = obj.pVertex.begin();  iVertex != obj.pVertex.end(); iVertex++ )
	{
		gluProject((*iVertex)->position.X(),(*iVertex)->position.Y(),(*iVertex)->position.Z(),v->model, v->proj, v->viewport, &_x,&_y,&_z);
		
		if( _x < mouse->x+zone && _x > mouse->x-zone &&	_y < mouse->y+zone && _y > mouse->y-zone )
		{
			if((*iVertex)->IsSelect!=true) 
			{
				(*iVertex)->IsSelect=true;

				if(cmpFace==0)
				{
					tmpFace[0]=(*iVertex)->id;
					cmpFace++;
					return;
				}
				else if(cmpFace==1)
				{
					tmpFace[1]=(*iVertex)->id;
					cmpFace++;
					return;
				}
				else if(cmpFace==2)
				{
					tmpFace[2]=(*iVertex)->id;
					obj.pFace.push_back(new Face(Faceid, GetVertex(tmpFace[0]),GetVertex(tmpFace[1]),GetVertex(tmpFace[2])));
					cmpFace=0;
					DeSelectAllVertex();
					//Faceid++;
					return;
				}
			}
		}
	}

}

Vertex* ObjectSystem::GetVertex(int id)
{
	for(iVertex = obj.pVertex.begin();  iVertex != obj.pVertex.end(); iVertex++ )
	{
		if((*iVertex)->id==id)
			return (*iVertex);
	}
	return NULL;
}

void ObjectSystem::CancelFace()
{
	cmpFace=0;
}

void ObjectSystem::DeleteFace()
{
	CancelFace();

	_iFace i	 = obj.pFace.begin();
	_iFace iEnd  = obj.pFace.end();

	for(; i != iEnd;)
	{
		if( (*i)->a->IsSelect==true ||
			(*i)->b->IsSelect==true ||
			(*i)->c->IsSelect==true )
		{
			Face *f=(*i);
			++i;
			obj.pFace.remove(f);
			delete f;
			continue;
		}
		++i;
	}
}

}