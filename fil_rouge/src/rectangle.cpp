
#include <sstream>

#include "rectangle.hpp"
#include "point.hpp"


Rectangle::Rectangle(Couleur c, Point const & p1, Point const & p2)
    : Rectangle(c, p1, p2.getX() - p1.getX(), p2.getY() - p1.getY()) {
}

Rectangle::Rectangle(Couleur c, Point const &p, int largeur, int hauteur)
    : Forme(Point(p), c, largeur, hauteur) {
}

Rectangle::Rectangle(Rectangle const & rectangle)
    : Rectangle(rectangle._couleur, Point(rectangle.getX(), rectangle.getY()), rectangle.getLargeur(), rectangle.getHauteur()) {
}


Rectangle * Rectangle::clone() const {
    return new Rectangle(*this);
}
std::string Rectangle::toString() const {
    std::ostringstream str;
    str << "Rectangle(" << getX() << ", " << getY() << ", " << getLargeur() << ", " << getHauteur() << ")";
    return str.str();
}

void Rectangle::setOrdre(size_t ordre) {
    _ordre = ordre;
}
