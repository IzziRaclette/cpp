
#include <iostream>
#include <sstream>

#include "point.hpp"


Point Point::origine;


Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : _x(x), _y(y) {}

Point::Point(Point const & p) : Point(p.getX(), p.getY()) {}

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

std::string Point::toString() const {
    std::ostringstream str;
    str << "(" << getX() << ", " << getY() << ")";
    return str.str();
}


Point & Point::operator=(Point const & p) {
    _x = p._x;
    _y = p._y;
    return *this;
}


std::ostream & operator<<(std::ostream & stream, Point const& p) {
    return stream << p.toString();
}
