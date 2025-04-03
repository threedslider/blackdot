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
Vector.hpp

Vector and Point classes

July 2024 : Creation
*/

#ifndef __Vector_hpp
#define __Vector_hpp

#include <iostream>
#include <cmath>


using namespace std;

namespace Blackdot
{

template <class T>
class Vector
{
    template <class T>
    friend class Point;

    T x, y, z;

public:
    Vector() : x(0), y(0), z(0) {}
    Vector(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    Vector(const Vector<T>& v) : x(v.x), y(v.x), z(v.z) {}

    const T X() const {return x;}
    const T Y() const {return y;}
    const T Z() const {return z;}

    void setx(const T _x) {x = _x;} 
    void sety(const T _y) {y = _y;} 
    void setz(const T _z) {z = _z;} 

    Vector<T>& operator=(const Vector<T>& v) 
    {
        x = v.x;
        y = v.y;
        z = v.z;

        return *this;
    }

    void zero() 
    {
        x = y = z = T(0);
    }

    bool operator==(const Vector<T>& v) const
    {
        return x == v.x && 
               y == v.y &&
               z == v.z;
    }

    bool operator!=(const Vector<T>& v)  const
    {
        return ! operator==(v);
    }

    Vector<T> operator+(const Vector<T>& v) const
    {
        return Vector<T>(x + v.x, y + v.y, z + v.z);
    }

    Vector<T>& operator+=(const Vector<T>& v) 
    {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    Vector<T> operator-() const
    {
        return Vector<T>(-x, -y, -z);
    }

     Vector<T>& operator-=(const Vector<T>& v) 
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;

        return *this;
    }

    Vector<T> operator*(const T& t) const
    {
        return Vector<T>(t*x, t*y, t*z);
    }

    Vector<T>& operator*=(const T& t) 
    {
        x *= t;
        y *= t;
        z *= t;

        return *this;
    } 

     Vector<T> operator/(const T& t) const
    {
        return Vector<T>(x/t, y/t, z/t);
    }

     Vector<T>& operator/=(const T& t) 
    {
        x /= t;
        y /= t;
        z /= t;

        return *this;
    } 

    T dot(const Vector<T>& v) const
    {
        return x*v.x + y*v.y + z*v.z;
    }

    Vector<T> cross(const Vector<T>& v) const
    {
        return Vector<T>(y*v.z - v.y*z, z*v.x - v.z*x, x*v.y - v.x*y);
    }


    Vector<T> mult(const Vector<T>& v) const
    {
        return Vector<T>(x * v.x, y * v.y, z * v.z);
    }

    Vector<T>& mult2(const Vector<T>& v) 
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;

        return *this;
    }

    T absNorm()
    {
        return fabs(x) + fabs(y) + fabs(z);
    }

    T min()
    {
        return ::min(x, ::min(y, z));
    }

    T max()
    {
        return ::max(x, ::max(y, z));
    }

    const T  norm2() const
    {
        return x*x + y*y + z*z;
    }

    T norm()
    {
        return (T) sqrt(double(norm2()));
    }

    Vector<T> getNormalized() const
    {
        return *this / norm();
    }

    Vector<T>& setNormalized()
    {
        *this /= norm();
        return *this;
    }

    void print()
    {
        cout << "x: " << x << " y: " << y << " z: " << z << endl;
    }

    T print_x()
    {
        return x; 
    }

    T print_y()
    {
        return y;
    }

    T print_z()
    {
        return z;
    }

    template <class U>
    friend ostream& operator<<(ostream& os, const Vector<U>& dt);
};


template <class T>
ostream& operator<<(ostream& os, const Vector<T>& dt)
{
    os << "x: " << dt.x << " y: " << dt.y << " z: " << dt.z << endl;
    return os;
}

template <class T>
inline Vector<T> operator*(T t, const Vector<T>& v)
{
    return Vector<T>(v.x*t, v.y*t, v.z*t);
}

template <class T>
class Point
{
    T x, y, z;

public:
    Point() : x(0), y(0), z(0) {}
    Point(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    Point(const Point<T>& p) : x(p.x), y(p.x), z(p.z) {}

    inline operator Vector<T> () const
    {
        return Vector<T>(x, y, z);
    }

    const T X() const {return x;}
    const T Y() const {return y;}
    const T Z() const {return z;}

    void setx(const T _x) {x = _x;} 
    void sety(const T _y) {y = _y;} 
    void setz(const T _z) {z = _z;} 

    Point<T>& operator=(const Point<T>& p) 
    {
        x = p.x;
        y = p.y;
        z = p.z;

        return *this;
    }

    void zero() 
    {
        x = y = z = T(0);
    }

    bool operator==(const Point<T>& p) const
    {
        return x == p.x && 
               y == p.y &&
               z == p.z;
    }

    bool operator!=(const Point<T>& p)  const
    {
        return ! operator==(p);
    }

    Point<T> operator+(const Point<T>& p) const
    {
        return Point<T>(x + p.x, y + p.y, z + p.z);
    }

    Point<T>& operator+=(const Point<T>& p) 
    {
        x += p.x;
        y += p.y;
        z += p.z;

        return *this;
    }

    Vector<T> operator-(const Point<T>& p) const
    {
        return Vector<T>(x-p.x, y-p.y, z-p.z);
    }

    Point<T> operator*(const T t) const
    {
        return Point<T>(x*t, y*t, z*t);
    }

    Point<T> operator/(const T t) const
    {
        return Point<T>(x/t, y/t, z/t);
    }

    Point<T> operator+(const Vector<T>& v) const
    {
        return Point<T>(x+v.x, y+v.y, z+v.z);
    }

    Point<T>& operator+=(const Vector<T>& v) const
    {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    Point<T> operator-(const Vector<T>& v) const
    {
        return Point<T>(x-v.x, y-v.y, z-v.z);
    }


    Point<T>& operator-=(const Vector<T>& v) const
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;

        return *this;
    }

    Point<T>& addx(const T dx)
    {
        x += dx;
        return *this;
    }

    Point<T>& addy(const T dy)
    {
        y += dy;
        return *this;
    }

    Point<T>& addz(const T dz)
    {
        z += dz;
        return *this;
    }

    T min()
    {
        return ::min(x, ::min(y, z));
    }

    T max()
    {
        return ::max(x, ::max(y, z));
    }

    Point<T> min(const Point<T>& p) const
    {
        return Point<T>(::min(x, p.x),
                        ::min(y, p.y),
                        ::min(z, p.z));
    }

    Point<T> max(const Point<T>& p) const
    {
        return Point<T>(::max(x, p.x),
                        ::max(y, p.y),
                        ::max(z, p.z));
    }

    void print()
    {
        cout << "x: " << x << " y: " << y << " z: " << z << endl;
    }

    template <class U>
    friend ostream& operator<<(ostream& os, const Point<U>& dt);
};

template <class T>
ostream& operator<<(ostream& os, const Point<T>& dt)
{
    os << "x: " << dt.x << " y: " << dt.y << " z: " << dt.z << endl;
    return os;
}

}

#endif //  __Vector_hpp


