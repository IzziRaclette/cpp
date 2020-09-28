
#include <iostream>
#include <string>

#include "forme.hpp"
#include "point.hpp"


std::ostream & operator<<(std::ostream & stream, Couleur const couleur) {
    std::string const names[]{
        "NOIR",
        "BLANC",
        "ROUGE",
        "VERT",
        "BLEU",
        "JAUNE"
    };

    stream << names[static_cast<int>(couleur)];
    return stream;
}


Forme::Forme(Point p, Couleur c, int width, int height)
    : _ID(Forme::_prochainID), _p(p), _couleur(c), _w(width), _h(height) {
    ++Forme::_prochainID;
}

Forme::~Forme() {}


unsigned Forme::_prochainID = 0;

unsigned Forme::prochainID(void) {
    return Forme::_prochainID;
}


unsigned Forme::getID(void) const {
    return _ID;
}

Couleur Forme::getCouleur(void) const {
    return _couleur;
}

void Forme::setCouleur(Couleur c) {
    _couleur = c;
}


Point const & Forme::getPoint(void) const {
    return _p;
}

Point & Forme::getPoint(void) {
    return _p;
}

void Forme::setPoint(Point p) {
    _p = p;
}

int Forme::getX(void) const {
    return _p.getX();
}

void Forme::setX(int x) {
    _p.setX(x);
}

int Forme::getY(void) const {
    return _p.getY();
}

void Forme::setY(int y) {
    _p.setY(y);
}

int Forme::getLargeur(void) const {
    return _w;
}

int Forme::getHauteur(void) const {
    return _h;
}
