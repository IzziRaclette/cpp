
#include <iostream>
#include <utility>

#include "vecteur.hpp"


Vecteur::Vecteur(size_t capacity)
 : _capacity(capacity), _index(0), _tab(new double[capacity]) {}

Vecteur::Vecteur(Vecteur const & vec)
 : _capacity(vec._capacity), _index(vec._index), _tab(new double[_capacity]) {
    std::copy(&vec._tab[0], &vec._tab[_capacity], _tab);
}

Vecteur::Vecteur(Vecteur && vec)
 : _capacity(std::exchange(vec._capacity, 0)),
   _index(std::exchange(vec._index, 0)),
   _tab(std::exchange(vec._tab, nullptr)) {}

Vecteur::~Vecteur() {
    delete[] _tab;
}


size_t Vecteur::capacity() const {
    return _capacity;
}

void Vecteur::push_back(double d) {
    if (_index >= _capacity) {
        realloc_tab(_capacity * 2);
    }

    _tab[_index] = d;
    _index++;
}

Vecteur Vecteur::map(double (*func)(double)) const {
    Vecteur vec(_capacity);
    for (size_t i = 0; i < _index; i++) {
        vec.push_back(func(_tab[i]));
    }
    return vec;
}

double * Vecteur::begin() const {
    return &_tab[0];
}

double * Vecteur::end() const {
    return &_tab[_capacity];
}

double Vecteur::operator[](int i) const {
    if (i < 0 || (size_t)i >= _capacity) {
        throw std::out_of_range("Index out of range");
    }

    return _tab[i];
}

double & Vecteur::operator[](int i) {
    if (i < 0 || (size_t)i >= _capacity) {
        throw std::out_of_range("Index out of range");
    }

    return _tab[i];
}

Vecteur & Vecteur::operator=(Vecteur other) {
    swap(*this, other);
    return *this;
}

void swap(Vecteur & vec1, Vecteur & vec2) {
    using std::swap;
    swap(vec1._capacity, vec2._capacity);
    swap(vec1._index,    vec2._index);
    swap(vec2._tab,      vec2._tab);
}


void Vecteur::realloc_tab(size_t new_capacity) {
    double * tmp = new double[new_capacity];
    std::copy(&_tab[0], &_tab[_capacity], tmp);
    delete[] _tab;
    _tab = tmp;

    _capacity = new_capacity;
}


std::ostream & operator<<(std::ostream & stream, Vecteur const & vec) {
    bool first = true;
    for (double d : vec) {
        if (!first) stream << ", ";
        first = false;
        stream << d;
    }
    return stream;
}
