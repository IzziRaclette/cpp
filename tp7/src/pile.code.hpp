
#include <utility>
#include <cstring>
#include <stdexcept>

#include "pile.hpp"


template<typename T>
Pile<T>::Pile(int capacity)
 : Pile(capacity >= 0 ? static_cast<size_t>(capacity) : throw std::invalid_argument("Cannot create stack with negative capacity")) {}

template<typename T>
Pile<T>::Pile(size_t capacity)
 : _index(0), _capacity(capacity != 0 ? capacity : throw std::invalid_argument("Cannot create stack with no capacity")), _data(new T[capacity]) {}

template<typename T>
Pile<T>::Pile(Pile<T> const & pile)
 : _index(pile._index), _capacity(pile._capacity), _data(new T[_capacity]) {
    memcpy(_data, pile._data, _capacity * sizeof(*_data));
}

template<typename T>
Pile<T>::Pile(Pile<T> && pile)
 : _index(pile._index), _capacity(pile._capacity), _data(std::exchange(pile._data, nullptr)) {}

template<typename T>
Pile<T>::~Pile() {
    delete[] _data;
}


template<typename T>
size_t Pile<T>::size() const {
    return _index;
}

template<typename T>
bool Pile<T>::empty() const {
    return _index == 0;
}

template<typename T>
T Pile<T>::top() const {
    if (_index == 0) throw std::out_of_range("Empty stack has no top element");
    return _data[_index - 1];
}

template<typename T>
void Pile<T>::push(T x) {
    if (_index == _capacity) throw std::out_of_range("Stack overflowed");
    _data[_index] = x;
    ++_index;
}

template<typename T>
T Pile<T>::pop() {
    if (_index == 0) throw std::out_of_range("Stack underflowed");
    --_index;
    return _data[_index];
}
