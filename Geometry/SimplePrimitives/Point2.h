/**
 *  interface to vector in geometry space
 */

/* include files */
#pragma once

#include <cmath>
#include "Geometry/Interfaces/GeometricDefinitions.h"



namespace Geometry {


/**
 *  class for represent vector in 2d geometry space
 */
template<class T> class Point2 {

protected:
    T x;                /**< first vector coordinate */
    T y;                /**< second vector coordinate */

public:
    /* constructors */
    Point2() { x = 0; y = 0; }
    Point2(T _x, T _y) { x = _x; y = _y; }
    Point2(const Point2 &other) { x = other.X(); y = other.Y(); }

    /* get vector coordinates */
    inline const T& X(void) const { return x; }
    inline const T& Y(void) const { return y; }
    inline T& X(void) { return x; }
    inline T& Y(void) { return y; }

    /* operations */
    template<typename T> friend Point2<T> operator+(const Point2<T> &firstArg, const Point2<T> &secondArg);
    template<typename T> friend Point2<T> operator-(const Point2<T> &firstArg, const Point2<T> &secondArg);
    template<typename T> friend bool operator==(const Point2<T> &firstArg, const Point2<T> &secondArg);
    template<typename T> friend T dotProduct(const Point2<T> &firstArg, const Point2<T> &secondArg);

    /* operators */
    inline Point2& operator= (const Point2 &other) { x = other.X(); y = other.Y(); return *this; }
    inline void add(const Point2 &other) { x += other.X(); y += other.Y(); }
    inline void addWeighted(const Point2 &other, T weight) { x += weight * other.X(); y += weight * other.Y(); }
    inline void setWeighted(const Point2 &other, T weight) { x = weight * other.X(); y = weight * other.Y(); }
    inline void minus(const Point2 &other) { x -= other.X(); y -= other.Y(); }
    inline void negate() { x *= -1; y *= -1; }
    inline void multiply(T k) { x *= k; y *= k; }
    inline void normate() { T k = length(); this->multiply(1 / k); }
    inline void takeMin(const Point2 &other) { x = x < other.X() ? x : other.X(); y = y < other.Y() ? y : other.Y(); }
    inline void takeMax(const Point2 &other) { x = x > other.X() ? x : other.X(); y = y > other.Y() ? y : other.Y(); }
    inline void print(void) const {}

    /* vectors parameters */
    inline T length(void) const { return std::sqrt(x * x + y * y); }
    inline T distance(const Point2 &other) const { Point2 dist = other - *this; return dist.length(); }
    inline T squaredDistance(const Point2 &other) const {
        return (other.X() - x) * (other.X() - x) + (other.Y() - y) * (other.Y() - y);
    }

    /* vector modifications */
    inline Point2 multiplied(T k) const { return Point2(x * k, y * k); }
    inline Point2 negative() { return Point2( -1 * x, -1 * y); }

    /* destructor */
    ~Point2() { }
};


/**
 *   summ of two vectors
 */
template<typename T> inline Point2<T> operator+(const Point2<T> &firstArg, const Point2<T> &secondArg) {
    Point2<T> result;
    result.x = firstArg.x + secondArg.x;
    result.y = firstArg.y + secondArg.y;
    return result;
}


/**
 *   difference of two vectors
 */
template<typename T> inline Point2<T> operator-(const Point2<T> &firstArg, const Point2<T> &secondArg) {
    Point2<T> result;
    result.x = firstArg.x - secondArg.x;
    result.y = firstArg.y - secondArg.y;
    return result;
}


/**
 *   comparison of two vectors
 */
template<typename T> inline bool operator==(const Point2<T> &firstArg, const Point2<T> &secondArg) {
    return std::abs(firstArg.x - secondArg.x) < EPSILON_VALUE &&
           std::abs(firstArg.y - secondArg.y) < EPSILON_VALUE;
}


/**
 *   dot product for two vectors
 */
template<typename T> inline T dotProduct(const Point2<T> &firstArg, const Point2<T> &secondArg) {
    return firstArg.X() * secondArg.X() + firstArg.Y() * secondArg.Y();
}


/**
 *    type definitions for vector
 */
typedef Point2<float> Point2f;
typedef Point2<double> Point2d;
typedef Point2<long double> Point2l;


} // namespace Geometry

