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


#ifndef __Viewport_hpp
#define __Viewport_hpp

#include "Mouse.hpp"

namespace Blackdot
{

	class Viewport
	{
	public:
		int		RenderMode;
		bool	CullFace;

		int		viewport[4];
		double	proj[16];
		double	model[16];
		double	Rot[3];
		double	Center[3];

		double	Zoom;

		Viewport();
		~Viewport();

		void	LoadViewport();

		void	SetupMatrix();
		void	SetupModelMatrix();

		void	SetViewport(int x, int y, int w, int h, double cx = 0, double cy = 0, double cz = 0);

		void	ZoomIn(double zoom);
		void	ZoomOut(double zoom);

		void	SetRot(int axis, double val);
		void	SetRot(double x, double y, double z);

		bool	IsWin(int x, int y); 
		void	DrawBord();

		void	SetCenter(Blackdot::Mouse* mouse);

		void	LoadRender();
		void	SetRender(int render);
		void	SetCullFace(bool cullface);
	};

}
#endif//_VIEWPORT_H