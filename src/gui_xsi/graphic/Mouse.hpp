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


#ifndef __Mouse_hpp
#define __Mouse_hpp

namespace Blackdot
{
    enum {
        POINT=0,
        LINE=1,
        FILL=2
    };
    
    enum {
        ORTHO=0,
        PERSP=1
    };
    
    enum {
        SINGLE_VIEWPORT=1,
        FOUR_VIEWPORT=0
    };

    class Mouse
    {
        public:

            int	state;
            int	button;
            int	active;	//Shift ,Ctrl

            int	Left, Right;
            int	Shift;
            int	Ctrl;
            int	Alt;
            int	None;
            int x;
            int	y;

            int	posx;
            int	posy;

            int	clicx;
            int	clicy;

            int	MouseIs;

    };

}

#endif//_MAIN_H