#include <iostream>
#include "point.hpp"
#include "vector.hpp"


Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : _x(x), _y(y) {}

Point::~Point() {}


int Point::getX() const {
    return _x;
}

void Point::setX(int x) {
    _x = x;
}

int Point::getY() const {
    return _y;
}

void Point::setY(int y) {
    _y = y;
}

std::ostream & operator<<(std::ostream & stream, Point const& p) {
    return stream << "(" << p.getX() << ", " << p.getY() << ")";
}
