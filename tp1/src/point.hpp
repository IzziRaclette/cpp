#ifndef POINT_HPP
#define POINT_HPP


#include <iostream>


class Vector;

class Point {
public:
    Point();
    Point(int x, int y);
    ~Point();

private:
    int _x;
    int _y;


public:
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
};


Vector operator-(Point const& p1, Point const& p2);

std::ostream & operator<<(std::ostream & stream, Point const& p);


#endif
