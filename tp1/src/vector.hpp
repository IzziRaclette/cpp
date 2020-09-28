#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>


class Point;

class Vector {
public:
    Vector();
    Vector(int x, int y);
    ~Vector();

private:
    int _x;
    int _y;


public:
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
};


Vector operator+(Vector const& v1, Vector const& v2);
Vector operator-(Vector const& v);
Vector operator-(Vector const& v1, Vector const& v2);

Vector operator*(int n, Vector const& v);
Vector operator*(Vector const& v, int n);

Point operator+(Point const& p, Vector const& v);
Point operator+(Vector const& v, Point const& p);

Vector operator-(Point const& p1, Point const& p2);

std::ostream & operator<<(std::ostream & stream, Vector const& v);


#endif
