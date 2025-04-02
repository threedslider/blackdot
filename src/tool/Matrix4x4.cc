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
  Matrix4x4.C

  Homogeneous vectors & matrices classes, 
 
  April 2 2025 
*/

#include "Matrix4x4.hpp"

namespace Blackdot
{
    template<typename T>
    Matrix4x4<T>::Matrix4x4(
        T m00, T m01, T m02, T m03,
        T m10, T m11, T m12, T m13,
        T m20, T m21, T m22, T m23,
        T m30, T m31, T m32, T m33
    ) {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::identity() {
        return Matrix4x4<T>(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::rotateX(T angle) {
        T rad = angle * M_PI / 180.0;
        T cosA = std::cos(rad);
        T sinA = std::sin(rad);

        return Matrix4x4<T>(
            1, 0, 0, 0,
            0, cosA, -sinA, 0,
            0, sinA, cosA, 0,
            0, 0, 0, 1
        );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::rotateY(T angle) {
        T rad = angle * M_PI / 180.0;
        T cosA = std::cos(rad);
        T sinA = std::sin(rad);

        return Matrix4x4<T>(
            cosA, 0, sinA, 0,
            0, 1, 0, 0,
            -sinA, 0, cosA, 0,
            0, 0, 0, 1
        );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::rotateZ(T angle) {
        T rad = angle * M_PI / 180.0;
        T cosA = std::cos(rad);
        T sinA = std::sin(rad);

        return Matrix4x4<T>(
            cosA, -sinA, 0, 0,
            sinA, cosA, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::scale(T sx, T sy, T sz) {
        return Matrix4x4<T>(
            sx, 0, 0, 0,
            0, sy, 0, 0,
            0, 0, sz, 0,
            0, 0, 0, 1
        );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::translate(T tx, T ty, T tz) {
        return Matrix4x4<T>(
            1, 0, 0, tx,
            0, 1, 0, ty,
            0, 0, 1, tz,
            0, 0, 0, 1
        );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::minor(int row, int col) const {
        Matrix4x4<T> mMinor;
        int minorRow = 0, minorCol = 0;

        for (int i = 0; i < 4; ++i) {
            if (i == row) continue; // Skip the row to remove
            minorCol = 0;
            for (int j = 0; j < 4; ++j) {
                if (j == col) continue; // Skip the column to remove

                mMinor.m[minorRow][minorCol] = m[i][j];
                minorCol++;
            }
            minorRow++;
        }

        return mMinor;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator+(const Matrix4x4<T>& other) const {
        Matrix4x4<T> result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] = m[i][j] + other.m[i][j];
            }
        }
        return result;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator-(const Matrix4x4<T>& other) const {
        Matrix4x4<T> result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] = m[i][j] - other.m[i][j];
            }
        }
        return result;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator/(const T& scalar) const {
        Matrix4x4<T> result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] = m[i][j] / scalar;
            }
        }
        return result;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4<T>& other) const {
        Matrix4x4<T> result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }

        return result;
    }

    template<typename T>
    Matrix4x4<T>& Matrix4x4<T>::operator+=(const Matrix4x4<T>& other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m[i][j] += other.m[i][j];
            }
        }
        return *this;  // Retourne l'objet courant pour permettre les chaines d'affectation
    }

    template<typename T>
    Matrix4x4<T>& Matrix4x4<T>::operator-=(const Matrix4x4<T>& other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m[i][j] -= other.m[i][j];
            }
        }
        return *this;  // Retourne l'objet courant pour permettre les chaines d'affectation
    }

    template<typename T>
    Matrix4x4<T>& Matrix4x4<T>::operator*=(const Matrix4x4<T>& other) {
        Matrix4x4<T> result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }

        // Copie du résultat dans la matrice actuelle
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m[i][j] = result.m[i][j];
            }
        }

        return *this;  // Retourne l'objet courant pour permettre les chaines d'affectation
    }

    template<typename T>
    Matrix4x4<T>& Matrix4x4<T>::operator/=(const T& scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m[i][j] /= scalar;
            }
        }
        return *this;  // Retourne l'objet courant pour permettre les chaines d'affectation
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::mult3x4(const Matrix4x4<T>& m3x4) const {
        Matrix4x4<T> result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.m[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    result.m[i][j] += m[i][k] * m3x4.m[k][j];
                }
            }
        }

        return result;
    }

    template<typename T>
    T Matrix4x4<T>::determinant() const {
        T det = 0;
        for (int i = 0; i < 4; ++i) {
            det += m[0][i] * ((i % 2 == 0 ? 1 : -1) * minor(0, i).determinant());
        }
        return det;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::inverse() const {
        T det = determinant();
        if (det == 0) {
            throw std::runtime_error("Matrix is singular, cannot invert.");
        }

        
        Matrix4x4<T> adjugate;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                adjugate.m[i][j] = cofactor(i, j).determinant();
            }
        }

       
        adjugate = adjugate.transpose();
       
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                adjugate.m[i][j] /= det;
            }
        }

        return adjugate;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::transpose() const {
        Matrix4x4<T> result = *this;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] = m[j][i];
            }
        }
        return result;
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::gaussianElimination() const {
        Matrix4x4<T> result = *this;
        
        for (int i = 0; i < 4; ++i) {
            
            if (result.m[i][i] == 0) {
                for (int j = i + 1; j < 4; ++j) {
                    if (result.m[j][i] != 0) {
                        std::swap(result.m[i], result.m[j]);
                        break;
                    }
                }
            }

           
            T pivot = result.m[i][i];
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] /= pivot;
            }

            
            for (int j = i + 1; j < 4; ++j) {
                T factor = result.m[j][i];
                for (int k = 0; k < 4; ++k) {
                    result.m[j][k] -= result.m[i][k] * factor;
                }
            }
        }

        return result;
    }

    template<typename T>
    Vector3D<T> Matrix4x4<T>::applyTransformation(const Vector3D<T>& v) const {
        T x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3];
        T y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3];
        T z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3];
        return Vector3D<T>(x, y, z);
    }

    template<typename T>
    void Matrix4x4<T>::setRotationX(double angle) {
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);

        *this = Matrix4x4<T>(
            1, 0, 0, 0,
            0, cosAngle, -sinAngle, 0,
            0, sinAngle, cosAngle, 0,
            0, 0, 0, 1
        );
    }

    template<typename T>
    void Matrix4x4<T>::setRotationY(double angle) {
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);

        *this = Matrix4x4<T>(
            cosAngle, 0, sinAngle, 0,
            0, 1, 0, 0,
            -sinAngle, 0, cosAngle, 0,
            0, 0, 0, 1
        );
    }
   
    template<typename T>
    void Matrix4x4<T>::setRotationZ(double angle) {
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);

        *this = Matrix4x4<T>(
            cosAngle, -sinAngle, 0, 0,
            sinAngle, cosAngle, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }
  
    template<typename T>
    void Matrix4x4<T>::setScale(const Vector3D<T>& scale) {
        *this = Matrix4x4<T>(
            scale.x, 0, 0, 0,
            0, scale.y, 0, 0,
            0, 0, scale.z, 0,
            0, 0, 0, 1
        );
    }

    template<typename T>
    void Matrix4x4<T>::setTranslation(const Vector3D<T>& translation) {
        *this = Matrix4x4<T>(
            1, 0, 0, translation.x,
            0, 1, 0, translation.y,
            0, 0, 1, translation.z,
            0, 0, 0, 1
        );
    }
    
    template<typename T>
    void Matrix4x4<T>::setRotation(const Vector3D<T>& axis, double angle) {
        Vector3D<T> u = axis.normalized();
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);
        double oneMinusCos = 1.0 - cosAngle;

        *this = Matrix4x4<T>(
            cosAngle + u.x * u.x * oneMinusCos, u.x * u.y * oneMinusCos - u.z * sinAngle, u.x * u.z * oneMinusCos + u.y * sinAngle, 0,
            u.y * u.x * oneMinusCos + u.z * sinAngle, cosAngle + u.y * u.y * oneMinusCos, u.y * u.z * oneMinusCos - u.x * sinAngle, 0,
            u.z * u.x * oneMinusCos - u.y * sinAngle, u.z * u.y * oneMinusCos + u.x * sinAngle, cosAngle + u.z * u.z * oneMinusCos, 0,
            0, 0, 0, 1
        );
    }   

    template<typename T>
    void Matrix4x4<T>::setTransformation(const Vector3D<T>& scale, const Vector3D<T>& rotation, const Vector3D<T>& translation) {
        
        Matrix4x4<T> scaleMatrix;
        scaleMatrix.setScale(scale);
    
        
        Matrix4x4<T> rotationXMatrix;
        rotationXMatrix.setRotationX(rotation.x);
        
        Matrix4x4<T> rotationYMatrix;
        rotationYMatrix.setRotationY(rotation.y);
    
        Matrix4x4<T> rotationZMatrix;
        rotationZMatrix.setRotationZ(rotation.z);
    
        
        Matrix4x4<T> translationMatrix;
        translationMatrix.setTranslation(translation);
    
        // To apply transformations in order : scale -> rotation -> translation
        *this = translationMatrix * rotationZMatrix * rotationYMatrix * rotationXMatrix * scaleMatrix;
    }

    template<typename T>
    void Matrix4x4<T>::print() const {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}