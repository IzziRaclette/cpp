
#include <sstream>

#include "liste.hpp"
#include "cercle.hpp"
#include "rectangle.hpp"


Liste::Liste(void)
    : _tailleTableaux(32),
      _nbCercles(0), _cercles(new Cercle * [_tailleTableaux]),
      _nbRectangles(0), _rectangles(new Rectangle * [_tailleTableaux]) {}

Liste::~Liste(void) {
    delete[] _cercles;
    delete[] _rectangles;
}


Cercle & Liste::cercle(size_t n) const {
    // TODO: n >= _nbCercles
    return *_cercles[n];
}

void Liste::ajouterCercle(Cercle & cercle) {
    _cercles[_nbCercles] = &cercle;
    cercle.setOrdre(_nbCercles);
    ++_nbCercles;
}

Rectangle & Liste::rectangle(size_t n) const {
    // TODO: n >= _nbRectangles
    return *_rectangles[n];
}

void Liste::ajouterRectangle(Rectangle & rectangle) {
    _rectangles[_nbRectangles] = &rectangle;
    rectangle.setOrdre(_nbRectangles);
    ++_nbRectangles;
}

std::string Liste::toString(void) const {
    std::ostringstream str;
    str << "Cercles {";
    for (size_t i = 0; i < _nbCercles; ++i) {
        if (i != 0) {
            str << ", ";
        }
        str << _cercles[i]->toString();
    }

    str << "}, Rectangles {";
    for (size_t i = 0; i < _nbRectangles; ++i) {
        if (i != 0) {
            str << ", ";
        }
        str << _rectangles[i]->toString();
    }

    str << "}";
    return str.str();
}
