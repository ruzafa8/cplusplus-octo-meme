#include "Span.hpp"

Span::Span(unsigned int n): _vector(new std::vector<int>()) {
	_vector->reserve(n);
}

Span::Span(Span const &other): _vector(new std::vector<int>()) {
	_vector->reserve(other._vector->capacity());
  	*this = other;
}

Span::~Span() {
	delete _vector;
}

Span &Span::operator=(Span const &other) {
  if (this != &other) {
	*_vector = *other._vector;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (_vector->size() >= _vector->capacity())
    throw ArrayFullException();
  _vector->push_back(n);
}

int Span::shortestSpan() {
  if (_vector->size() <= 1)
    throw NotEnoughElementsException();
  std::sort(_vector->begin(), _vector->end());
  int min = _vector->at(1) - _vector->at(0);
  for (unsigned int i = 2; i < _vector->size(); i++) {
    int diff = _vector->at(i) - _vector->at(i - 1);
    if (diff < min)
      min = diff;
  }
  return min;
}

int Span::longestSpan() {
  if (_vector->size() <= 1)
    throw NotEnoughElementsException();
  std::sort(_vector->begin(), _vector->end());
  return _vector->back() - _vector->front();
}
