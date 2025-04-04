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



#ifndef __ViewportSystem_hpp
#define __ViewportSystem_hpp

#include "Viewport.h"

namespace Blackdot
{

    class ViewportSystem
    {
        int		MouseIs;			
        bool	ViewSolo;			

        int		w, h;		

        Viewport	v[5];			
    public:

        ViewportSystem();
        ~ViewportSystem();

        bool	Init(int _w, int _h);

        void	Reshape(int w, int h);

        void	Mouse(int x, int y);	
        int		GetMouseIs();			

        void	LoadOrtho();

        void	LoadSolo();				
        void	LoadViewport(int num);	
        void	LoadViewportSolo();		

        void	Solo(bool b);			
        void	SetWinSolo(int win);	
        void	InvSolo();				
        bool	GetSolo();				


        Viewport*	GetViewport();		

        void	DrawContour();
        void	DrawRect(Mouse *mouse);

        void	ZoomIn(double zoom);
        void	ZoomOut(double zoom);

        void	ResetRotate(int axis);	
        void	Rotate(int axis, double val);
        void	Center(Mouse *mouse);

        void	SetRender(int render);
        void	SetCullFace(bool CullFace);
        void	InvCullFace();

    };

}


#endif