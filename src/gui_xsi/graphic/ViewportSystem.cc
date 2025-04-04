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

#include <GL/GLFW.h>
#include "ViewportSystem.hpp"



ViewportSystem::ViewportSystem()
{
	ViewSolo=FOUR_VIEWPORT;
	w=h=1;
	MouseIs=1;

}

ViewportSystem::~ViewportSystem()
{
}

bool ViewportSystem::Init(int _w, int _h)
{
	w=_w;
	h=_h;

	v[0].SetRot(0,0,0);
	v[0].SetViewport(0,0, w, h, w/2, h/2);	//on deplace le centre w/2 h/2


	v[1].SetViewport(0 ,h/2 ,w/2, h/2);
	v[1].SetRot(0,90,0);

	v[2].SetViewport(w/2 ,h/2 ,w/2, h/2);
	v[2].SetRot(0,0,0);

	v[3].SetViewport(w/2 ,0 ,w/2, h/2);
	v[3].SetRot(-90,0,0);

	v[4].SetViewport(0 ,0 ,w/2, h/2);
	v[4].SetRot(-45,45,0);


	v[1].ZoomIn(10);
	v[2].ZoomIn(10);
	v[3].ZoomIn(10);
	v[4].ZoomIn(10);

	return true;
}

void ViewportSystem::LoadOrtho()
{
	v[0].SetViewport(0,0, w, h, w/2, h/2, 0);

}


void ViewportSystem::LoadViewport(int num)
{
	if(ViewSolo==SINGLE_VIEWPORT)
	{
		v[MouseIs].LoadViewport();
	}
	else
	{
		v[num].LoadViewport();
	}
}

void ViewportSystem::LoadViewportSolo()
{
	v[MouseIs].LoadViewport();
}

void ViewportSystem::Mouse(int x, int y)
{
	if(ViewSolo==FOUR_VIEWPORT)
	{
			 if(v[1].IsWin(x, y)) MouseIs=1;
		else if(v[2].IsWin(x, y)) MouseIs=2;
		else if(v[3].IsWin(x, y)) MouseIs=3;
		else if(v[4].IsWin(x, y)) MouseIs=4;
	}
}

int ViewportSystem::GetMouseIs()
{
	return MouseIs;
}

void ViewportSystem::Reshape(int _w, int _h)
{
	w=_w;
	h=_h;

	v[0].SetViewport(0,0, w, h);

	if(ViewSolo==SINGLE_VIEWPORT)
	{
		v[MouseIs].SetViewport(0,0, _w, _h);
	}
	else
	{
		v[2].SetViewport(w/2, h/2, w/2, h/2);
		v[3].SetViewport(w/2,   0, w/2, h/2);
		v[1].SetViewport(0,   h/2, w/2, h/2);
		v[4].SetViewport(0,     0, w/2, h/2);
	}
}

void ViewportSystem::Solo(bool b)
{
	ViewSolo=b;
	if(ViewSolo==SINGLE_VIEWPORT)
	{
		v[MouseIs].SetViewport(0,0,w, h);
	}
	Reshape(w, h);
}

void ViewportSystem::InvSolo()
{
	ViewSolo=!ViewSolo;

	if(ViewSolo==SINGLE_VIEWPORT)
	{
		v[MouseIs].SetViewport(0,0,w, h);
	}

	Reshape(w, h);
}

void ViewportSystem::SetWinSolo(int win)
{
	ViewSolo=SINGLE_VIEWPORT;
	MouseIs=win;
	v[win].SetViewport(0,0, w, h);
	Reshape(w, h);
}

bool ViewportSystem::GetSolo()
{
	return ViewSolo;
}

Viewport* ViewportSystem::GetViewport()
{
	return &v[MouseIs];
}

  
void ViewportSystem::DrawContour()
{
	v[0].LoadViewport();
	if(ViewSolo==FOUR_VIEWPORT)
	{
		for(int i=1; i <=4; i++)
		{
			if(MouseIs==i)
				glColor3f(0,0,1);
			else
				glColor3f(0,0,0);
			v[i].DrawBord();
		}
	}
	else
	{
		glColor3f(0,0,0);
		v[MouseIs].DrawBord();
	}
}

void ViewportSystem::DrawRect(Mouse *mouse)
{
	v[0].LoadViewport();
	GLdouble pos[3];
	GLdouble mov[3];

	gluUnProject (	mouse->x, mouse->y, 0.0,
					v[0].model, v[0].proj, v[0].viewport, &pos[0], &pos[1], &pos[2]); 

	gluUnProject (	mouse->posx, mouse->posy, 0.0,
					v[0].model, v[0].proj, v[0].viewport, &mov[0], &mov[1], &mov[2]); 


	glColor3f(1,1.7,1.7);
	glBegin(GL_LINE_LOOP);
		glVertex2i(pos[0]	, pos[1]);
		glVertex2i(mov[0]	, pos[1]);
		glVertex2i(mov[0]	, mov[1]);
		glVertex2i(pos[0]	, mov[1]);
	glEnd();
}


void ViewportSystem::ZoomIn(double z)
{
	v[MouseIs].ZoomIn(z);
}

void ViewportSystem::ZoomOut(double z)
{
	v[MouseIs].ZoomOut(z);
}


void ViewportSystem::Rotate(int axis, double val)
{
	v[MouseIs].SetRot(axis, val);
}


void ViewportSystem::ResetRotate(int axis)
{
	switch(axis)
	{
	case 1:v[MouseIs].SetRot(0, 0, 0);
		break;
	case 2:v[MouseIs].SetRot(-90, 0, 0);
		break;
	case 0:v[MouseIs].SetRot(0, 90, 0);
		break;
	}

}

void ViewportSystem::Center(Mouse *mouse)
{
	v[MouseIs].SetCenter(mouse);
}

void ViewportSystem::SetRender(int render)
{
	v[MouseIs].SetRender(render);
}

void ViewportSystem::SetCullFace(bool cullface)
{
	v[MouseIs].SetCullFace(cullface);
}

void ViewportSystem::InvCullFace()
{
	v[MouseIs].CullFace=!v[MouseIs].CullFace;
}
