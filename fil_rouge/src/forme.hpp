#ifndef FORME_HPP
#define FORME_HPP

class Point;

#include "point.hpp"


enum class Couleur {
    NOIR,
    BLANC,
    ROUGE,
    VERT,
    BLEU,
    JAUNE
};

std::ostream & operator<<(std::ostream & stream, Couleur const color);


/* Abstraite */
class Forme {
public:
    Forme(Point p = Point::origine, Couleur c = Couleur::BLEU, int width = 0, int height = 0);
    Forme(Forme const & forme) = delete;
    virtual ~Forme();

private:
    static unsigned _prochainID;

public:
    static unsigned prochainID(void);

protected:
    unsigned const _ID;
    Point _p;
    Couleur _couleur;
    int _w;
    int _h;

public:
    unsigned getID(void) const;

    Point const & getPoint(void) const;
    Point & getPoint(void);
    void setPoint(Point p);
    int getX(void) const;
    void setX(int x);
    int getY(void) const;
    void setY(int y);

    int getLargeur(void) const;
    int getHauteur(void) const;

    Couleur getCouleur(void) const;
    void setCouleur(Couleur c);

    virtual Forme * clone() const = 0;

    virtual std::string toString(void) const = 0;
};

#endif
