#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <string>
#include <cstddef>

class Point;

#include "forme.hpp"


class Rectangle : public Forme {
public:
    Rectangle(Couleur c = Couleur::BLEU, Point const & p1 = Point::origine, Point const & p2 = Point::origine);
    Rectangle(Couleur c, Point const & haut_gauche, int largeur, int hauteur);
    Rectangle(Rectangle const & rectangle);

private:
    size_t _ordre;

public:
    Rectangle * clone() const;

    std::string toString() const;
    void setOrdre(size_t ordre);
};


#endif
