#ifndef PILE_HPP
#define PILE_HPP

#include <cstddef>


class Pile {
private:
    size_t _index;
    size_t _capacity;
    int * _data;

public:
    Pile(int capacity);
    Pile(size_t capacity = 256);
    Pile(Pile const & other);
    Pile(Pile && other);
    ~Pile();

public:
    size_t size() const;
    bool empty() const;
    int top() const;
    void push(int x);
    int pop();

public:
    Pile & operator=(Pile other);
};

#endif
