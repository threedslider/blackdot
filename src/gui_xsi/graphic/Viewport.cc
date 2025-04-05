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
#include "Viewport.hpp"

namespace Blackdot
{

	Viewport::Viewport()
	{
		Rot[0] = Rot[1] = Rot[2] = 0;
		Center[0] = Center[1] = Center[2] = 0;
		Zoom = 1;
		RenderMode = LINE;
		CullFace = false;
	}

	Viewport::~Viewport()
	{
	}

	void Viewport::SetViewport(int x, int y, int w, int h, double cx, double cy, double cz)
	{
		Center[0] = cx;
		Center[1] = cy;
		Center[2] = cz;

		viewport[0] = x;
		viewport[1] = y;
		viewport[2] = w;
		viewport[3] = h;
		SetupMatrix();
	}

	void Viewport::SetupMatrix()
	{

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho((-viewport[2] / 2) / Zoom, (viewport[2] / 2) / Zoom, (-viewport[3] / 2) / Zoom, (viewport[3] / 2) / Zoom, 100000, -100000);

		glGetDoublev(GL_PROJECTION_MATRIX, proj);
		SetupModelMatrix();
	}

	void Viewport::SetupModelMatrix()
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glRotatef(Rot[0], 1, 0, 0);
		glRotatef(Rot[1], 0, 1, 0);
		glRotatef(Rot[2], 0, 0, 1);

		glTranslated(-Center[0], -Center[0], -Center[0]);
		glGetDoublev(GL_MODELVIEW_MATRIX, model);
	}

	void Viewport::LoadViewport()
	{
		glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixd(proj);
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixd(model);

		LoadRender();
	}


	void Viewport::SetRot(int axis, double val)
	{
		Rot[axis] += val;
		SetupMatrix();
	}

	void Viewport::SetRot(double x, double y, double z)
	{
		Rot[0] = x;
		Rot[1] = y;
		Rot[2] = z;
		SetupMatrix();
	}

	void Viewport::ZoomIn(double zoom)
	{
		Zoom *= 1 + zoom;
		SetupMatrix();
	}

	void Viewport::ZoomOut(double zoom)
	{
		Zoom /= 1 + zoom;
		SetupMatrix();
	}


	bool Viewport::IsWin(int x, int y)
	{
		return (x > viewport[0] && x < viewport[0] + viewport[2] &&
			y > viewport[1] && y < viewport[1] + viewport[3]);
	}


	void Viewport::DrawBord()
	{
		glBegin(GL_LINE_LOOP);
		glVertex2iv(viewport);
		glVertex2i(viewport[0] + viewport[2] - 1, viewport[1]);
		glVertex2i(viewport[0] + viewport[2] - 1, viewport[1] + viewport[3] - 1);
		glVertex2i(viewport[0], viewport[1] + viewport[3] - 1);
		glEnd();
	}

	void Viewport::SetCenter(Blackdot::Mouse* mouse)
	{
		GLdouble wx, wy, wz;
		GLdouble _wx, _wy, _wz;
		GLdouble x, y, z;

		gluProject(0, 0, 0, model, proj, viewport, &x, &y, &z);

		gluUnProject((GLdouble)mouse->x, (GLdouble)mouse->y, z,
			model, proj, viewport, &wx, &wy, &wz);

		gluUnProject((GLdouble)mouse->clicx, (GLdouble)mouse->clicy, z,
			model, proj, viewport, &_wx, &_wy, &_wz);


		Center[0] += wx - _wx;
		Center[1] += wy - _wy;
		Center[2] += wz - _wz;

		SetupModelMatrix();
	}

	void Viewport::SetRender(int render)
	{
		RenderMode = render;
	}

	void Viewport::SetCullFace(bool cullface)
	{
		CullFace = cullface;
	}

	void Viewport::LoadRender()
	{
		if (CullFace == true)
			glEnable(GL_CULL_FACE);
		else
			glDisable(GL_CULL_FACE);

		switch (RenderMode)
		{

		case POINT:
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			glDisable(GL_LIGHTING);
			break;

		case LINE:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDisable(GL_LIGHTING);
			break;

		case FILL:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glEnable(GL_CULL_FACE);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			break;
		}
	}

}