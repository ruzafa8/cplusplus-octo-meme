#include <iostream>
#include "Span.hpp"

Span *createSpan(unsigned int n) {
	std::vector<int> randomNumbers(n);
	Span *sp = new Span(n);

	srand(time(NULL));
	std::generate(randomNumbers.begin(), randomNumbers.end(), std::rand);
	sp->addNumber(randomNumbers.begin(), randomNumbers.end());
	return sp;
}

int main() {
  {
    Span sp(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
      std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
      std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    Span sp(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
      sp.addNumber(42);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    Span sp(1);
    try {
      sp.shortestSpan();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    Span sp(1);
    try {
      sp.longestSpan();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    Span *sp = createSpan(10000);
    try {
      std::cout << "Shortest span: " << sp->shortestSpan() << std::endl;
      std::cout << "Longest span: " << sp->longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    delete sp;
  }
  {
    Span *sp = createSpan(10000);
    try {
      sp->addNumber(42);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    delete sp;
  }
  return 0;
}