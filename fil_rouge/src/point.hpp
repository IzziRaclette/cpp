#ifndef POINT_HPP
#define POINT_HPP

#include <string>


class Point {
public:
    static Point origine;

public:
    Point();
    Point(int x, int y);
    Point(Point const & p);
    ~Point();

private:
    int _x;
    int _y;


public:
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    std::string toString() const;

    Point & operator=(Point const & p);
};


std::ostream & operator<<(std::ostream & stream, Point const& p);


#endif
