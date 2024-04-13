#include "Span.hpp"

Span::Span(unsigned int n): _n(n), _array(new int[n]), _size(0) {}

Span::Span(Span const &other) {
  *this = other;
}

Span::~Span() {
  delete []_array;
}

Span &Span::operator=(Span const &other) {
  if (this != &other) {
    delete []_array;
    _n = other._n;
    _array = new int[_n];
    _size = other._size;
    for (unsigned int i = 0; i < _size; i++)
      _array[i] = other._array[i];
  }
  return *this;
}

void Span::addNumber(int n) {
  if (_size >= _n)
    throw ArrayFullException();
  _array[_size++] = n;
}

int Span::shortestSpan() {
  if (_size <= 1)
    throw NotEnoughElementsException();
  std::sort(_array, _array + _size);
  int min = _array[1] - _array[0];
  for (unsigned int i = 2; i < _size; i++) {
    int diff = _array[i] - _array[i - 1];
    if (diff < min)
      min = diff;
  }
  return min;
}

int Span::longestSpan() {
  if (_size <= 1)
    throw NotEnoughElementsException();
  std::sort(_array, _array + _size);
  return _array[_size - 1] - _array[0];
}
