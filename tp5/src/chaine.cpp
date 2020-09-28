
#include <cstring>
#include <iostream>
#include <utility>

#include "chaine.hpp"


Chaine::Chaine(char const * str) : _tab(nullptr) {
    setStr(str);
}

Chaine::Chaine(size_t capacite)
 : _capacite(capacite), _tab(new char[_capacite + 1]) {
    _tab[0] = '\0';
}

Chaine::Chaine(Chaine const & other) : Chaine(other.getCapacite()) {
    strcpy(_tab, other.c_str());
}

Chaine::Chaine(Chaine && other)
 : _capacite(std::exchange(other._capacite, 0)), _tab(std::exchange(other._tab, nullptr)) {}

Chaine::~Chaine() {
    delete[] _tab;
}


size_t Chaine::getCapacite(void) const {
    return _capacite;
}

char const * Chaine::c_str(void) const {
    return _tab;
}

void Chaine::afficher(std::ostream & stream) const {
    stream << _tab;
}

void Chaine::setStr(char const * str) {
    delete[] _tab;

    if (str) {
        _capacite = strlen(str);
        _tab = new char [_capacite + 1];
        strcpy(_tab, str);
    } else {
        _capacite = -1;
        _tab = nullptr;
    }
}

Chaine & Chaine::operator=(Chaine other) {
    swap(*this, other);
    return *this;
}

void swap(Chaine & str1, Chaine & str2) {
    using std::swap;

    swap(str1._capacite, str2._capacite);
    swap(str1._tab,      str2._tab);
}

char Chaine::operator[](int i) const {
    if (_tab == nullptr) {
        throw null_ptr("Chaine does not contain a string");
    }

    if (i < 0 || (size_t)i > _capacite) {
        throw std::out_of_range("Index out of range");
    }

    return _tab[i];
}

char & Chaine::operator[](int i) {
    if (_tab == nullptr) {
        throw null_ptr("Chaine does not contain a string");
    }

    if (i < 0 || (size_t)i > _capacite) {
        throw std::out_of_range("Index out of range");
    }

    return _tab[i];
}


void afficherParValeur(Chaine const & str) {
    str.afficher();
}

void afficherParValeur(Chaine const & str, std::ostream & stream) {
    str.afficher(stream);
}


std::ostream & operator<<(std::ostream & stream, Chaine const & str) {
    str.afficher(stream);
    return stream;
}

Chaine operator+(Chaine const & str1, Chaine const & str2) {
    char buf[str1.getCapacite() + str2.getCapacite() + 1];
    strcpy(buf, str1.c_str());
    strcat(buf, str2.c_str());
    return Chaine(buf);
}
