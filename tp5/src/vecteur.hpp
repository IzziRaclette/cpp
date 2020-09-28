#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <cstddef>


class Vecteur {
public:
    Vecteur(size_t capacity = 4);
    Vecteur(Vecteur const & vec);
    Vecteur(Vecteur && vec);
    ~Vecteur();

private:
    size_t _capacity;
    size_t _index;
    double * _tab;

public:
    size_t capacity() const;
    void push_back(double d);
    Vecteur map(double (*func)(double)) const;

    /* For range-for */
    double * begin() const;
    double * end() const;

    double operator[](int i) const;
    double & operator[](int i);
    Vecteur & operator=(Vecteur vec);
    friend void swap(Vecteur & vec1, Vecteur & vec2);

private:
    void realloc_tab(size_t new_capacity);
};

Vecteur operator+(Vecteur const & v1, Vecteur const & v2);

#endif
