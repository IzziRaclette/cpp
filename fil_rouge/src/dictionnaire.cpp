
#include <algorithm>
#include <iterator>

#include "dictionnaire.hpp"


Dictionnaire::Dictionnaire() {
    for (char c = 'a'; c <= 'z'; c++) {
        _dict.insert({ c, ListeMotsTries() });
    }
}

std::ostream & operator<<(std::ostream & stream, Dictionnaire const & dict) {
    for (char c = 'a'; c <= 'z'; c++) {
        stream << dict._dict.at(c);
    }
    return stream;
}
