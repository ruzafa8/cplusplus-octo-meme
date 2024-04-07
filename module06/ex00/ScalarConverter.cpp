#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) { *this = other; }
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
  if (this != &other) {}
  return (*this);
}

void ScalarConverter::convert(const std::string &value) {
  // Missing:
  // - Overflows
  // - Nan, inf, -inf, nanf, inff, -inff
  void (*treatItLike[4]) (const std::string &) = {
    &ScalarConverter::treatItLikeChar, &ScalarConverter::treatItLikeInt, &ScalarConverter::treatItLikeFloat, &ScalarConverter::treatItLikeDouble
  };
  Kind kind[4] = { ScalarConverter::CHAR, ScalarConverter::INT, ScalarConverter::FLOAT, ScalarConverter::DOUBLE };
  try {
    Kind type = ScalarConverter::getKind(value);
    for (int i = 0; i < 4; i++)
      if (type == kind[i])
        return (*treatItLike[i])(value);
  } catch (ScalarConverter::ImpossibleConversionException &e) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
}

ScalarConverter::Kind ScalarConverter::getKind(const std::string &value) {
  if (value.length() == 1 && !std::isdigit(value[0])) {
    return ScalarConverter::CHAR;
  }
  bool isDecimal = false;
  for (size_t i = 0; i < value.length(); i++) {
    if (!ScalarConverter::isValidNumber(value, i)) {
      throw ScalarConverter::ImpossibleConversionException();
    }
    if (value[i] == '.' && isDecimal) {
      throw ScalarConverter::ImpossibleConversionException();
    }
    if (value[i] == '.' || value[i] == 'f') {
      isDecimal = true;
    }
  }
  return !isDecimal ? ScalarConverter::INT
    : (value[value.length() - 1] == 'f'
      ? ScalarConverter::FLOAT
      : ScalarConverter::DOUBLE
    );
}

bool ScalarConverter::isValidNumber(const std::string &value, size_t pos) {
  char c = value[pos];
  size_t length = value.length();
  return (pos == 0 && (c == '-' || c == '+')) || std::isdigit(c) || c == '.' || (pos == length - 1 && c == 'f');
}

void ScalarConverter::treatItLikeChar(const std::string &value) {
  char c = value[0];
  int i = static_cast<int>(c);
  ScalarConverter::printAll(c, i, static_cast<float>(i), static_cast<double>(i));
}

void ScalarConverter::treatItLikeInt(const std::string &value) {
  int i = std::atoi(value.c_str());
  ScalarConverter::printAll(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
}

void ScalarConverter::treatItLikeFloat(const std::string &value) {
  float f = static_cast<float>(std::atof(value.c_str()));
  ScalarConverter::printAll(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
}

void ScalarConverter::treatItLikeDouble(const std::string &value) {
  double d = std::atof(value.c_str());
  ScalarConverter::printAll(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
}

void ScalarConverter::printChar(char c) {
  std::cout << "char: ";
  if (isprint(c))
    std::cout << "'" << c << "'";
  else std::cout << "Non displayable";
  std::cout << std::endl;
}

void ScalarConverter::printInt(int i) {
  if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
    std::cout << "int: impossible" << std::endl;
  } else std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
  if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max()) {
    std::cout << "float: impossible" << std::endl;
  } else {
    std::stringstream ss;
    ss << f;
    std::string str = ss.str();

    if (str.find('.') == std::string::npos) {
        str += ".0";
    }
    std::cout << "float: " << str << "f" << std::endl;
  }
}

void ScalarConverter::printDouble(double d) {
  if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max()) {
    std::cout << "double: impossible" << std::endl;
  } else { 
    std::stringstream ss;
    ss << d;
    std::string str = ss.str();

    if (str.find('.') == std::string::npos) {
        str += ".0";
    }
    std::cout << "double: " << str << std::endl;
  }
}

void ScalarConverter::printAll(char c, int i, float f, double d) {
  ScalarConverter::printChar(c);
  ScalarConverter::printInt(i);
  ScalarConverter::printFloat(f);
  ScalarConverter::printDouble(d);
}