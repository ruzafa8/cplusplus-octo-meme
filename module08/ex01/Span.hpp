#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <algorithm>

class Span {
  private:
    unsigned int  _n;
    int           *_array;
    unsigned int  _size;

  public:
    Span(unsigned int n);
    Span(Span const &other);
    ~Span();

    Span &operator=(Span const &other);

    void addNumber(int n);
  
    template<typename T>
    void addNumber(T begin, T end) {
      if (_size + std::distance(begin, end) > _n)
        throw ArrayFullException();
      for (T it = begin; it != end; it++)
        _array[_size++] = *it;
    }

    int shortestSpan();
    int longestSpan();

    class ArrayFullException: public std::exception {
      public:
        virtual const char *what() const throw() {
          return "Array is full";
        }
    };

    class NotEnoughElementsException: public std::exception {
      public:
        virtual const char *what() const throw() {
          return "Not enough elements";
        }
    };
};

#endif