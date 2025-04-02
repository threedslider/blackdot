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

#include "Matrix3x3.hpp"
#include <stdexcept>

namespace Blackdot
{

template <typename T>
Matrix3x3<T>::Matrix3x3(T a11, T a12, T a13,
                        T a21, T a22, T a23,
                        T a31, T a32, T a33) {
    mat = {{{a11, a12, a13}, {a21, a22, a23}, {a31, a32, a33}}};
}

template <typename T>
void Matrix3x3<T>::print() const {
    for (const auto& row : mat) {
        for (T val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::operator+(const Matrix3x3& other) const {
    return Matrix3x3(
        mat[0][0] + other.mat[0][0], mat[0][1] + other.mat[0][1], mat[0][2] + other.mat[0][2],
        mat[1][0] + other.mat[1][0], mat[1][1] + other.mat[1][1], mat[1][2] + other.mat[1][2],
        mat[2][0] + other.mat[2][0], mat[2][1] + other.mat[2][1], mat[2][2] + other.mat[2][2]
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::operator-(const Matrix3x3& other) const {
    return Matrix3x3(
        mat[0][0] - other.mat[0][0], mat[0][1] - other.mat[0][1], mat[0][2] - other.mat[0][2],
        mat[1][0] - other.mat[1][0], mat[1][1] - other.mat[1][1], mat[1][2] - other.mat[1][2],
        mat[2][0] - other.mat[2][0], mat[2][1] - other.mat[2][1], mat[2][2] - other.mat[2][2]
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::operator*(T scalar) const {
    return Matrix3x3(
        mat[0][0] * scalar, mat[0][1] * scalar, mat[0][2] * scalar,
        mat[1][0] * scalar, mat[1][1] * scalar, mat[1][2] * scalar,
        mat[2][0] * scalar, mat[2][1] * scalar, mat[2][2] * scalar
    );
}

template <typename T>
Vector<T> Matrix3x3<T>::operator*(const Vector<T>& v) const {
    return Vector<T>(
        mat[0][0] * v.x + mat[0][1] * v.y + mat[0][2] * v.z,
        mat[1][0] * v.x + mat[1][1] * v.y + mat[1][2] * v.z,
        mat[2][0] * v.x + mat[2][1] * v.y + mat[2][2] * v.z
    );
}

template <Typename T>
Matrix3x3<T> Matrix3x3<T>::operator/(T scalar) const {
    if (scalar == 0) throw std::invalid_argument("Division by zero");
    return Matrix3x3(
        mat[0][0] / scalar, mat[0][1] / scalar, mat[0][2] / scalar,
        mat[1][0] / scalar, mat[1][1] / scalar, mat[1][2] / scalar,
        mat[2][0] / scalar, mat[2][1] / scalar, mat[2][2] / scalar
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::operator*(const Matrix3x3& other) const {
    Matrix3x3 result(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result.mat[i][j] += mat[i][k] * other.mat[k][j];
            }
        }
    }
    return result;
}

template <typename T>
T Matrix3x3<T>::determinant() const {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::cofactor() const {
    return Matrix3x3(
        mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1], -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]), mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0],
        -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]), mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0], -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]),
        mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1], -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]), mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::transpose() const {
    return Matrix3x3(
        mat[0][0], mat[1][0], mat[2][0],
        mat[0][1], mat[1][1], mat[2][1],
        mat[0][2], mat[1][2], mat[2][2]
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::inverse() const {
    T det = determinant();
    if (det == 0) {
        throw std::invalid_argument("The inverse is singular, impossible inverse.");
    }

    Matrix3x3 adjugate = cofactor().transpose();
    return adjugate / det;
}

template <typename T>
T Matrix3x3<T>::quadraticForm(const Vector<T>& v) const {
    Vector<T> result = (*this) * v;
    return result.dot(v);
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::scale(T sx, T sy, T sz) const {
    return Matrix3x3(
        mat[0][0] * sx, mat[0][1] * sy, mat[0][2] * sz,
        mat[1][0] * sx, mat[1][1] * sy, mat[1][2] * sz,
        mat[2][0] * sx, mat[2][1] * sy, mat[2][2] * sz
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::rotateX(T angle) {
    T c = std::cos(angle), s = std::sin(angle);
    return Matrix3x3(
        1, 0, 0,
        0, c, -s,
        0, s, c
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::rotateY(T angle) {
    T c = std::cos(angle), s = std::sin(angle);
    return Matrix3x3(
        c, 0, s,
        0, 1, 0,
        -s, 0, c
    );
}

template <typename T>
Matrix3x3<T> Matrix3x3<T>::rotateZ(T angle) {
    T c = std::cos(angle), s = std::sin(angle);
    return Matrix3x3(
        c, -s, 0,
        s, c, 0,
        0, 0, 1
    );
}

template <typename T>
Vector<T> Matrix3x3<T>::cramer(const Vector<T>& b) const {
    T det = determinant();
    if (det == 0) {
        throw std::invalid_argument("The determinant is null, incompatible system.");
    }

    Matrix3x3 m1 = *this;
    m1.mat[0][0] = b.x; m1.mat[1][0] = b.y; m1.mat[2][0] = b.z;
    Matrix3x3 m2 = *this;
    m2.mat[0][1] = b.x; m2.mat[1][1] = b.y; m2.mat[2][1] = b.z;
    Matrix3x3 m3 = *this;
    m3.mat[0][2] = b.x; m3.mat[1][2] = b.y; m3.mat[2][2] = b.z;

    return Vector<T>(m1.determinant() / det, m2.determinant() / det, m3.determinant() / det);
}


}