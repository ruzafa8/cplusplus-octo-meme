#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>
# include <algorithm>

class Span {
  private:
    std::vector<int>	*_vector;

  public:
    Span(unsigned int n);
    Span(Span const &other);
    ~Span();

    Span &operator=(Span const &other);

    void addNumber(int n);
  
    template<typename T>
    void addNumber(T begin, T end) {
		if (_vector->size() >= _vector->capacity())
			throw ArrayFullException();
		_vector->insert(_vector->end(), begin, end);
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