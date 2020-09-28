#include <iostream>
#include "vector.hpp"
#include "point.hpp"


Vector::Vector() : Vector(0, 0) {}

Vector::Vector(int x, int y) : _x(x), _y(y) {}

Vector::~Vector() {}


int Vector::getX() const {
    return _x;
}

void Vector::setX(int x) {
    _x = x;
}

int Vector::getY() const {
    return _y;
}

void Vector::setY(int y) {
    _y = y;
}


Vector operator+(Vector const& v1, Vector const& v2) {
    return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY());
}
Vector operator-(Vector const& v) {
    return -1 * v;
}
Vector operator-(Vector const& v1, Vector const& v2) {
    return v1 + -v2;
}

Vector operator*(int n, Vector const& v) {
    return Vector(v.getX() * n, v.getY() * n);
}
Vector operator*(Vector const& v, int n) {
    return n * v;
}

Point operator+(Point const& p, Vector const& v) {
    return Point(p.getX() + v.getX(), p.getY() + v.getY());
}
Point operator+(Vector const& v, Point const& p) {
    return p + v;
}

Vector operator-(Point const& p1, Point const& p2) {
    return Vector(p1.getX() - p2.getX(), p1.getY() - p2.getY());
}

std::ostream & operator<<(std::ostream & stream, Vector const& v) {
    return stream << "(" << v.getX() << ", " << v.getY() << ")";
}
