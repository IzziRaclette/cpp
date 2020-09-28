
#include <string>
#include <iostream>

#include "zz.hpp"


ZZ::ZZ(std::string nom, std::string prenom, double note)
 : _nom(nom), _prenom(prenom), _note(note) {}

bool ZZ::operator<(ZZ const & right) const {
    return _note < right._note;
}

std::ostream & operator<<(std::ostream & stream, ZZ const & zz) {
    return stream << zz._nom << " " << zz._prenom << " : " << zz._note;
}
