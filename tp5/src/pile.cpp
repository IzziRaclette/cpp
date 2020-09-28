
#include <utility>
#include <cstring>
#include <stdexcept>

#include "pile.hpp"


Pile::Pile(int capacity)
 : Pile(capacity >= 0 ? static_cast<size_t>(capacity) : throw std::invalid_argument("Cannot create stack with negative capacity")) {}

Pile::Pile(size_t capacity)
 : _index(0), _capacity(capacity != 0 ? capacity : throw std::invalid_argument("Cannot create stack with no capacity")), _data(new int[capacity]) {}

Pile::Pile(Pile const & pile)
 : _index(pile._index), _capacity(pile._capacity), _data(new int[_capacity]) {
    memcpy(_data, pile._data, _capacity * sizeof(*_data));
}

Pile::Pile(Pile && pile)
 : _index(pile._index), _capacity(pile._capacity), _data(std::exchange(pile._data, nullptr)) {}

Pile::~Pile() {
    delete[] _data;
}


size_t Pile::size() const {
    return _index;
}

bool Pile::empty() const {
    return _index == 0;
}

int Pile::top() const {
    if (_index == 0) throw std::out_of_range("Empty stack has no top element");
    return _data[_index - 1];
}

void Pile::push(int x) {
    if (_index == _capacity) throw std::out_of_range("Stack overflowed");
    _data[_index] = x;
    ++_index;
}

int Pile::pop() {
    if (_index == 0) throw std::out_of_range("Stack underflowed");
    --_index;
    return _data[_index];
}
