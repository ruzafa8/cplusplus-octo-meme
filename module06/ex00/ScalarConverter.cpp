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
  float f = static_cast<float>(c);
  double d = static_cast<double>(c);
  ScalarConverter::printChar(c);
  ScalarConverter::printInt(i);
  ScalarConverter::printFloat(f);
  ScalarConverter::printDouble(d);
}

void ScalarConverter::treatItLikeInt(const std::string &value) {
  int i = ScalarConverter::parseInt(value);
  char c = static_cast<char>(i);
  ScalarConverter::printChar(c);
  ScalarConverter::parseAll(value);
}

void ScalarConverter::treatItLikeFloat(const std::string &value) {
  float f = static_cast<float>(std::atof(value.c_str()));
  ScalarConverter::printChar(c);
  ScalarConverter::parseAll(value);
}

void ScalarConverter::treatItLikeDouble(const std::string &value) {
  double d = std::atof(value.c_str());
  char c = static_cast<char>(d);
  int i = static_cast<int>(d);
  float f = static_cast<float>(d);
  ScalarConverter::printChar(c);
  ScalarConverter::parseAll(value);
}

void ScalarConverter::printChar(char c) {
  std::cout << "char: ";
  if (isprint(c))
    std::cout << "'" << c << "'";
  else std::cout << "Non displayable";
  std::cout << std::endl;
}

void ScalarConverter::printInt(int i) {
  std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
  std::stringstream ss;
  ss << f;
  std::string str = ss.str();

  if (str.find('.') == std::string::npos) {
      str += ".0";
  }
  std::cout << "float: " << str << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
  std::stringstream ss;
  ss << d;
  std::string str = ss.str();

  if (str.find('.') == std::string::npos) {
      str += ".0";
  }
  std::cout << "double: " << str << std::endl;
}

void ScalarConverter::parseAll(const std::string &value) {
  // Missing char
  ScalarConverter::parseInt(value);
  ScalarConverter::parseFloat(value);
  ScalarConverter::parseDouble(value);
}

void ScalarConverter::parseInt(const std::string &value) {
  long res = std::strtol(value.c_str(), nullptr, 10);
  if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
    std::cout << "int: impossible" << std::endl;
  else printInt(static_cast<int>(res));
}

void ScalarConverter::parseFloat(const std::string &value) {
  float res = std::strtof(value.c_str(), nullptr);
  if (errno == ERANGE)
    std::cout << "float: impossible" << std::endl;
  else printFloat(res);
}

void ScalarConverter::parseDouble(const std::string &value) {
  double res = std::strtod(value.c_str(), nullptr);
  if (errno == ERANGE)
    std::cout << "double: impossible" << std::endl;
  else printDouble(res);
}

