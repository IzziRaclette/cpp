
#include <string>
#include <iostream>

#include "zz.hpp"


ZZ::ZZ(std::string name, std::string firstname, double note)
 : _name(name), _firstname(firstname), _note(note) {}

/*
bool ZZ::operator<(ZZ const & right) const {
    return _note < right._note;
}*/
bool ZZ::operator<(ZZ const & right) const {
    int result = _name.compare(right._name);
    if(result == 0) {
        result = _firstname.compare(right._firstname);
    }
    return result < 0;
}

std::ostream & operator<<(std::ostream & stream, ZZ const & zz) {
    return stream << zz._name << " " << zz._firstname << " : " << zz._note;
}


bool ZZ::NoteComparator::operator()(ZZ const & left, ZZ const & right) const {
    return left._note < right._note;
}
