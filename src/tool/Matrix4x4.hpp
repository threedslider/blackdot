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
  Matrix4x4.hpp

  
  April 2 2025 
*/


#ifndef __Matrix4x4_hpp
#define __Matrix4X4_hpp


#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Vector.hpp"

namespace Blackdot
{

    template<typename T>
    class Matrix4x4 {
    public:
        T m[4][4];

        Matrix4x4(
            T m00, T m01, T m02, T m03,
            T m10, T m11, T m12, T m13,
            T m20, T m21, T m22, T m23,
            T m30, T m31, T m32, T m33
        );

        
        static Matrix4x4<T> identity();
        static Matrix4x4<T> rotateX(T angle);
        static Matrix4x4<T> rotateY(T angle);
        static Matrix4x4<T> rotateZ(T angle);
        static Matrix4x4<T> rotate(const Vector<T>& axis, T angle);
        static Matrix4x4<T> scaleMatrix(const Vector<T>& scale);
        static Matrix4x4<T> translate(const Vector<T>& translation);
        static Matrix4x4<T> transformation(const Vector<T>& scale, const Vector<T>& rotationAxis, T rotationAngle, const Vector<T>& translation);



        Matrix4x4<T> operator+(const Matrix4x4<T>& other) const;
        Matrix4x4<T> operator-(const Matrix4x4<T>& other) const;
        Matrix4x4<T> operator/(const T& scalar) const;
        Matrix4x4<T> operator*(const Matrix4x4<T>& other) const;

        Matrix4x4<T>& operator+=(const Matrix4x4<T>& other);
        Matrix4x4<T>& operator-=(const Matrix4x4<T>& other);
        Matrix4x4<T>& operator*=(const Matrix4x4<T>& other);
        Matrix4x4<T>& operator/=(const T& scalar);

        
        T determinant() const;
        Matrix4x4<T> inverse() const;
        Matrix4x4<T> transpose() const;
        Matrix4x4<T> gaussianElimination() const;
        Matrix4x4<T> minor(int row, int col) const;

        Matrix4x4<T> mult3x4(const Matrix4x4<T>& m3x4) const;
        
        Vector<T> applyTransformation(const Vector<T>& v) const;

        void print() const;


    };

}

#endif