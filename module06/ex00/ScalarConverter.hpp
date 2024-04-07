#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <limits>

class ScalarConverter {
  private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);

    static void treatItLikeChar(const std::string &value);
    static void treatItLikeInt(const std::string &value);
    static void treatItLikeFloat(const std::string &value);
    static void treatItLikeDouble(const std::string &value);

    static void printAll(char c, int i, float f, double d);
    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

    enum Kind { CHAR, INT, FLOAT, DOUBLE };
    static Kind getKind(const std::string &value);

    class ImpossibleConversionException : public std::exception {
      public:
        virtual const char *what() const throw() { return ""; }
    };

    static bool isValidNumber(const std::string &value, size_t pos);
  public:
    ~ScalarConverter();

    static void convert(const std::string &value);

};

#endif