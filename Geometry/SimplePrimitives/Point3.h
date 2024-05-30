/**
 *  interface to vector in geometry space
 */

/* include files */
#pragma once

#include <cmath>
#include "Geometry/Interfaces/GeometricDefinitions.h"



namespace Geometry {


/**
 *  class for represent vector in 3d geometry space
 */
template<typename T> class Point3 {

protected:
    T x;                /**< first vector coordinate */
    T y;                /**< second vector coordinate */
    T z;                /**< third vector coordinate */

public:
    /* constructors */
    Point3() { x = 0; y = 0; z = 0; }
    Point3(T _x, T _y, T _z) { x = _x; y = _y; z = _z; }
    Point3(const Point3 &other) { x = other.X(); y = other.Y(); z = other.Z(); }

    /* get vector coordinates */
    inline const T& X(void) const { return x; }
    inline const T& Y(void) const { return y; }
    inline const T& Z(void) const { return z; }
    inline T& X(void) { return x; }
    inline T& Y(void) { return y; }
    inline T& Z(void) { return z; }

    /* operations */
    template<typename T> friend Point3<T> operator+(const Point3<T> &firstArg, const Point3<T> &secondArg);
    template<typename T> friend Point3<T> operator-(const Point3<T> &firstArg, const Point3<T> &secondArg);
    template<typename T> friend bool operator==(const Point3<T> &firstArg, const Point3<T> &secondArg);
    template<typename T> friend T dotProduct(const Point3<T> &firstArg, const Point3<T> &secondArg);
    template<typename T> friend Point3<T> vecProduct(const Point3<T> &firstArg, const Point3<T> &secondArg);

    /* operators */
    inline Point3& operator=(const Point3 &other) { x = other.X(); y = other.Y(); z = other.Z(); return *this; }
    inline void add(const Point3 &other) { x += other.X(); y += other.Y(); z += other.Z(); }
    inline void addWeighted(const Point3 &other, T weight) {
        x += weight * other.X(); y += weight * other.Y(); z += weight * other.Z();
    }
    inline void setWeighted(const Point3 &other, T weight) {
        x = weight * other.X(); y = weight * other.Y(); z = weight * other.Z();
    }
    inline void minus(const Point3 &other) { x -= other.X(); y -= other.Y(); z -= other.Z(); }
    inline void negate() { x *= -1; y *= -1; z *= -1; }
    inline void multiply(T k) { x *= k; y *= k; z *= k; }
    inline void normate() { T k = length(); this->multiply(1 / k); }
    inline void takeMin(const Point3 &other) {
        x = x < other.X() ? x : other.X(); y = y < other.Y() ? y : other.Y(); z = z < other.Z() ? z : other.Z();
    }
    inline void takeMax(const Point3 &other) {
        x = x > other.X() ? x : other.X(); y = y > other.Y() ? y : other.Y(); z = z > other.Z() ? z : other.Z();
    }
    inline void print(void) const {}

    /* vectors parameters */
    inline T length(void) const { return std::sqrt(x * x + y * y + z * z); }
    inline T distance(const Point3 &other) const { Point3 dist = other - *this; return dist.length(); }
    inline T squaredDistance(const Point3 &other) const {
        return (other.X() - x) * (other.X() - x) + (other.Y() - y) * (other.Y() - y) +
               (other.Z() - z) * (other.Z() - z);
    }

    /* vector modifications */
    inline Point3 multiplied(T k) const { return Point3(x * k, y * k, z * k); }
    inline Point3 negative() { return Point3(-1 * x, -1 * y, -1 * z); }

    /* destructor */
    ~Point3() { }
};


/**
 *   summ of two vectors
 */
template<typename T> inline Point3<T> operator+(const Point3<T> &firstArg, const Point3<T> &secondArg) {
    Point3<T> result;
    result.x = firstArg.x + secondArg.x;
    result.y = firstArg.y + secondArg.y;
    result.z = firstArg.z + secondArg.z;
    return result;
}


/**
 *   difference of two vectors
 */
template<typename T> inline Point3<T> operator-(const Point3<T> &firstArg, const Point3<T> &secondArg) {
    Point3<T> result;
    result.x = firstArg.x - secondArg.x;
    result.y = firstArg.y - secondArg.y;
    result.z = firstArg.z - secondArg.z;
    return result;
}


/**
 *   equality of two vectors
 */
template<typename T> inline bool operator==(const Point3<T> &firstArg, const Point3<T> &secondArg) {
    return std::abs(firstArg.x - secondArg.x) < EPSILON_VALUE &&
           std::abs(firstArg.y - secondArg.y) < EPSILON_VALUE &&
           std::abs(firstArg.z - secondArg.z) < EPSILON_VALUE;
}


/**
 *   dot product for two vectors
 */
template<typename T> inline T dotProduct(const Point3<T> &firstArg, const Point3<T> &secondArg) {
    return firstArg.X() * secondArg.X() + firstArg.Y() * secondArg.Y() + firstArg.Z() * secondArg.Z();
}


/**
 *   vector product for two vectors
 */
template<typename T> inline Point3<T> vecProduct(const Point3<T> &firstArg, const Point3<T> &secondArg) {
    Point3<T> result;
    result.x = firstArg.y * secondArg.z - firstArg.z * secondArg.y;
    result.y = firstArg.z * secondArg.x - firstArg.x * secondArg.z;
    result.z = firstArg.x * secondArg.y - firstArg.y * secondArg.x;
    return result;
}


/**
 *    type definitions for vector
 */
typedef Point3<float> Point3f;
typedef Point3<double> Point3d;
typedef Point3<long double> Point3l;


} // namespace Geometry

