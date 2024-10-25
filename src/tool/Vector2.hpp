/* 
This file is part of Blackdot
Copyright (C) 2024 Laurent Le Flem

This program is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software Foundation, 
either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. 
If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __Vector2_hpp
#define __Vector2_hpp

#include <cmath>

using namespace std;

/*
Vector2.hpp

2D Vector and 2D Point classes

August 2024
*/

namespace Blackdot 
{

template <class T>
class Vector2D
{
    template <class T>
    friend class Point2D;

    T x, y;

    public:

    Vector2D()
    {
        x = T(0);
        y = T(0);
    }

    Vector2D( const T _x, const T _y )
    {
    x = _x;
    y = _y;
    }

    Vector2D( const Vector2D<T>& v )
    {
    x = v.x;
    y = v.y;
    }

    const T X() const { return x; }
    const T Y() const { return y; }

    void setx(const T _x) {x = _x;} 
    void sety(const T _y) {y = _y;}

    Vector2D<T>& operator=(const Vector2D<T>& v) 
    {
        x = v.x;
        y = v.y;

        return *this;
    }

    void zero() 
    {
        x = y = T(0);
    }

    bool operator==(const Vector2D<T>& v) const
    {
        return x == v.x && 
               y == v.y;
    }

    bool operator!=(const Vector2D<T>& v)  const
    {
        return ! operator==(v);
    }

     Vector2D<T> operator+(const Vector2D<T>& v) const
    {
        return Vector2D<T>(x + v.x, y + v.y);
    }

    Vector2D<T>& operator+=(const Vector2D<T>& v) 
    {
        x += v.x;
        y += v.y;

        return *this;
    }

    Vector2D<T> operator-() const
    {
        return Vector2D<T>(-x, -y);
    }

     Vector2D<T>& operator-=(const Vector2D<T>& v) 
    {
        x -= v.x;
        y -= v.y;

        return *this;
    }

    Vector2D<T> operator*(const T& t) const
    {
        return Vector2D<T>(t*x, t*y);
    }

    Vector2D<T>& operator*=(const T& t) 
    {
        x *= t;
        y *= t;

        return *this;
    } 

     Vector2D<T> operator/(const T& t) const
    {
        return Vector2D<T>(x/t, y/t);
    }

     Vector2D<T>& operator/=(const T& t) 
    {
        x /= t;
        y /= t;

        return *this;
    } 

    T dot(const Vector2D<T>& v) const
    {
        return x*v.x + y*v.y;
    }

    T cross(const Vector2D<T>& v) const
    {
        return x * v.y - v.x * y;
    }

    T absNorm()
    {
        return fabs(x) + fabs(y);
    }

    const T  norm2() const
    {
        return x*x + y*y;
    }

    T norm()
    {
        return (T) sqrt(double(norm2()));
    }

    Vector2D<T> getNormalized() const
    {
        return *this / norm();
    }

    Vector2D<T>& setNormalized()
    {
        *this /= norm();
        return *this;
    }

    T min()
    {
        return ::min(x, y);
    }

    T max()
    {
        return ::max(x, y);
    }




};


template <class T>
inline Vector2D<T> operator*(T t, const Vector2D<T>& v)
{
    return Vector2D<T>(v.x*t, v.y*t);
}

template <class T>
class Point2D
{
    T x, y;

    public:

    Point2D() : x(0), y(0) {}
    Point2D(T _x, T _y) : x(_x), y(_y) {}
    Point2D(const Point2D<T>& p) : x(p.x), y(p.x) {}

    inline operator Vector2D<T> () const
    {
        return Vector2D<T>(x, y);
    }

    const T X() const {return x;}
    const T Y() const {return y;}

    void setx(const T _x) {x = _x;} 
    void sety(const T _y) {y = _y;} 

    Point2D<T>& operator=(const Point2D<T>& p) 
    {
        x = p.x;
        y = p.y;

        return *this;
    }

    void zero() 
    {
        x = y = T(0);
    }

    bool operator==(const Point2D<T>& p) const
    {
        return x == p.x && 
               y == p.y;
    }

    bool operator!=(const Point2D<T>& p)  const
    {
        return ! operator==(p);
    }

    Point2D<T> operator+(const Point2D<T>& p) const
    {
        return Point2D<T>(x + p.x, y + p.y);
    }

    Point2D<T>& operator+=(const Point2D<T>& p) 
    {
        x += p.x;
        y += p.y;

        return *this;
    }

    Vector2D<T> operator-(const Point2D<T>& p) const
    {
        return Vector2D<T>(x-p.x, y-p.y);
    }

    Point2D<T> operator*(const T t) const
    {
        return Point2D<T>(x*t, y*t);
    }

    Point2D<T> operator/(const T t) const
    {
        return Point2D<T>(x/t, y/t);
    }

    Point2D<T> operator+(const Vector2D<T>& v) const
    {
        return Point<T>(x+v.x, y+v.y);
    }

    Point2D<T>& operator+=(const Vector2D<T>& v) const
    {
        x += v.x;
        y += v.y;

        return *this;
    }

    Point2D<T> operator-(const Vector2D<T>& v) const
    {
        return Point2D<T>(x-v.x, y-v.y);
    }


    Point2D<T>& operator-=(const Vector2D<T>& v) const
    {
        x -= v.x;
        y -= v.y;

        return *this;
    }

    Point2D<T>& addx(const T dx)
    {
        x += dx;
        return *this;
    }

    Point2D<T>& addy(const T dy)
    {
        y += dy;
        return *this;
    }

    T min()
    {
        return ::min(x, y);
    }

    T max()
    {
        return ::max(x, y);
    }

    Point2D<T> min(const Point2D<T>& p) const
    {
        return Point<T>(::min(x, p.x),
                        ::min(y, p.y));
    }

    Point2D<T> max(const Point2D<T>& p) const
    {
        return Point<T>(::max(x, p.x),
                        ::max(y, p.y));
    }
};

}


#endif //  __Vector2_hpp
