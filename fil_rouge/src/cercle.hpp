#ifndef CERCLE_HPP
#define CERCLE_HPP

#include <string>
#include <cstddef>

class Point;

#include "forme.hpp"


class Cercle : public Forme {
public:
    Cercle(Point const & p = Point::origine, Couleur c = Couleur::BLEU, int rayon = 0);
    Cercle(Cercle const & cercle);

private:
    size_t _ordre;

public:
    int getRayon(void) const;
    void setRayon(int r);

    Cercle * clone() const;

    std::string toString() const;
    void setOrdre(size_t ordre);
};


#endif
