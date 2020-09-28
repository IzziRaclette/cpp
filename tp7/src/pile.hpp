#ifndef PILE_HPP
#define PILE_HPP

#include <cstddef>


template <typename T>
class Pile {
private:
    size_t _index;
    size_t _capacity;
    T * _data;

public:
    Pile(int capacity);
    Pile(size_t capacity = 256);
    Pile(Pile const & other);
    Pile(Pile && other);
    ~Pile();

public:
    size_t size() const;
    bool empty() const;
    T top() const;
    void push(T x);
    T pop();

public:
    Pile & operator=(Pile other);
};

#include "pile.code.hpp"

#endif
