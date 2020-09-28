#ifndef LISTE_HPP
#define LISTE_HPP

#include <cstddef>

class Cercle;
class Rectangle;


class Liste {
public:
    Liste(void);
    ~Liste(void);

private:
    size_t const _tailleTableaux;

    size_t _nbCercles;
    Cercle ** _cercles;

    size_t _nbRectangles;
    Rectangle ** _rectangles;

public:
    Cercle & cercle(size_t n) const;
    void ajouterCercle(Cercle & cercle);

    Rectangle & rectangle(size_t n) const;
    void ajouterRectangle(Rectangle & rectangle);

    std::string toString(void) const;
};

#endif
