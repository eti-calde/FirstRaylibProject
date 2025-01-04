#pragma once

#include <raylib.h>
#include <math.h>
#include <string>
#include <stdexcept>
#include <type_traits>

template <typename T>
class Vec2 {
    static_assert(std::is_arithmetic<T>::value, "Vec2 can only be used with arithmetic types");
public:
    T x = 0;
    T y = 0;

    Vec2() = default;

    Vec2(T xin, T yin) 
        : x(xin), y(yin) 
    {}

    Vec2(const Vector2& vec) 
        : x(static_cast<T>(vec.x)), y(static_cast<T>(vec.y)) 
    {}

    T getX() const { return x; }
    T getY() const { return y; }

    // Vector Addition
    Vec2<T> operator + (const Vec2<T>& rhs) const {
        return Vec2<T>(x + rhs.x, y + rhs.y);
    }  

    // Vector Subtraction
    Vec2<T> operator - (const Vec2<T>& rhs) const {
        return Vec2<T>(x - rhs.x, y - rhs.y);
    }

    // Scalar Multiplication
    Vec2<T> operator * (const T scalar) const {
        return Vec2<T>(x * scalar, y * scalar);
    }

    // Scalar Division
    Vec2<T> operator / (const T scalar) const {
        return Vec2<T>(x / scalar, y / scalar);
    }

    // Compost Addition
    Vec2<T>& operator+=(const Vec2<T>& rhs) {
        x += rhs.x;
        y += rhs.y;
    return *this;
    }

    // Compost Subtraction
    Vec2<T>& operator-=(const Vec2<T>& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    // Compost Multiplication
    Vec2<T>& operator*=(const T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    //compost Division
    Vec2<T>& operator/=(const T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // Equality
    bool operator == (const Vec2<T>& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    // Inequality
    bool operator != (const Vec2<T>& rhs) const {
        return x != rhs.x || y != rhs.y;
    }

    // Access
    T& operator[](size_t index) {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Index out of range");
    }

    // Access to const
    const T& operator[](size_t index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Index out of range");
    }

    // Negation
    Vec2<T> operator - () const {
        return Vec2<T>(-x, -y);
    }

    T dot(const Vec2<T>& rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    std::string toString() const {
        return std::string("Vec2(") + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    T distanceSquared(const Vec2<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return dx * dx + dy * dy;
    }

    T euclideanDistance(const Vec2<T>& other) const {
        return std::sqrt(distanceSquared(other));
    }

};


using Vec2f = Vec2<float>;




//     float dist(const Vec2& rhs) const {
//         // TODO
//         return 0;
//     }