
#include <algorithm>
#include <iterator>
#include <functional>

#include "liste_mots_tries.hpp"


void ListeMotsTries::ajouterMot(std::string const & mot) {
    _liste.insert(std::upper_bound(debut(), fin(), mot), mot);
}

void ListeMotsTries::retirerMot(std::string const & mot) {
    const_iterator elem = std::find(debut(), fin(), mot);
    if (elem != fin()) {
        _liste.erase(elem);
    }
}

void ListeMotsTries::inserer(const_iterator const & debut, const_iterator const & fin) {
    std::for_each(debut, fin, [&](std::string const & mot) { ajouterMot(mot); });
    // Aternate possibility
    // using namespace std::placeholders;
    // std::for_each(debut, fin, std::bind(&ListeMotsTries::ajouterMot, *this, _1));
}

int ListeMotsTries::getNbMots() const {
    return _liste.size();
}

ListeMotsTries::const_iterator ListeMotsTries::debut() const {
    return _liste.begin();
}

ListeMotsTries::const_iterator ListeMotsTries::fin() const {
    return _liste.end();
}

std::ostream & operator<<(std::ostream & stream, ListeMotsTries const & liste) {
    std::copy(liste.debut(), liste.fin(), std::ostream_iterator<std::string>(stream, " "));
    return stream;
}
