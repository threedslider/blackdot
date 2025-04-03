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
  Matrix3x3.hpp

  
  April 2 2025 
*/

#ifndef __Matrix3x3_hpp
#define __Matrix3x3_hpp

#include <iostream>
#include <array>
#include <cmath>
#include "Vector.hpp"

namespace Blackdot
{
  template <typename T>
  class Matrix3x3 {
  public:
      std::array<std::array<T, 3>, 3> mat;

      Matrix3x3(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33);

      void print() const;

      Matrix3x3 operator+(const Matrix3x3& other) const;
      Matrix3x3 operator-(const Matrix3x3& other) const;
      Matrix3x3 operator*(T scalar) const;
      Vector<T> operator*(const Vector<T>& v) const;
      Matrix3x3 operator/(T scalar) const;
      Matrix3x3 operator*(const Matrix3x3& other) const;

      T determinant() const;
      Matrix3x3 cofactor() const;
      Matrix3x3 transpose() const;
      Matrix3x3 inverse() const;
      T quadraticForm(const Vector<T>& v) const;

      Matrix3x3 scale(const Vector<T>& s) const;
      static Matrix3x3 rotateX(T angle);
      static Matrix3x3 rotateY(T angle);
      static Matrix3x3 rotateZ(T angle);
      Matrix3x3 rotation(const Vector<T>& axis, T angle);

      Vector<T> cramer(const Vector<T>& b) const;
  };

}

