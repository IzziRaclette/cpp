
#include <sstream>

#include "cercle.hpp"
#include "point.hpp"


Cercle::Cercle(Point const & p, Couleur c, int rayon)
    : Forme(Point(p.getX() - rayon, p.getY() - rayon), c, rayon * 2, rayon * 2) {}

Cercle::Cercle(Cercle const & cercle)
    : Cercle(cercle._p, cercle._couleur, cercle.getRayon()) {
}


int Cercle::getRayon(void) const {
    return getLargeur() / 2;
}

void Cercle::setRayon(int r) {
    _p.setX(_p.getX() - (r - getRayon()));
    _p.setY(_p.getY() - (r - getRayon()));
    _w = r * 2;
    _h = r * 2;
}


Cercle * Cercle::clone() const {
    return new Cercle(*this);
}


std::string Cercle::toString() const {
    std::stringstream str;
    str << "Cercle(" << getPoint() << ", " << getCouleur() << ", " << getRayon() << ")";
    return str.str();
}

void Cercle::setOrdre(size_t ordre) {
    _ordre = ordre;
}
