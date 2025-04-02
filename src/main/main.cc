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


/*
Main program

Laurent Le Flem

August 06 2024 (My great day !)
*/

#include "tool/Vector.hpp"
#include "tool/Vector2.hpp"

using namespace Blackdot;

int main()
{
    Vector<float> v1(5.2f, 10.0f, 50.0f);

    Point<float> p1(100.0f, 50.0f, 200.0f);

    Point<float> p2(10.0f, 10.0f, 20.0f);

    Point<float> result;

    result =  p1 - v1;

    result.print();

    Vector<float> result_vector;

    result_vector =  p1 - p2;

    cout <<  result_vector << endl;

    result_vector.print();


    Vector2D<float> v2(10.0f, 5.0f);
    Point2D<float> p3(100.0f, 50.0f);
    Point2D<float> r2;

    r2 = p3 - v2;
    
    return 0;

}