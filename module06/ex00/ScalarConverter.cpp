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
  if (value.length() == 3 && value[0] == '\'' && value[2] == '\'') {
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
  char c = value[1];
  ScalarConverter::printChar(c);
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::treatItLikeInt(const std::string &value) {
  try {
    int i = ScalarConverter::parseInt(value);
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
      throw ScalarConverter::ImpossibleConversionException();
    char c = static_cast<char>(i);
    ScalarConverter::printChar(c);
  } catch(ScalarConverter::ImpossibleConversionException &e) {
    std::cout << "char: impossible" << std::endl;
  }
  ScalarConverter::printInt(value);
  ScalarConverter::printFloat(value);
  ScalarConverter::printDouble(value);
}

void ScalarConverter::treatItLikeFloat(const std::string &value) {
  try {
    float f = static_cast<float>(std::atof(value.c_str()));
    if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
      throw ScalarConverter::ImpossibleConversionException();
    char c = static_cast<char>(f);
    ScalarConverter::printChar(c);
  } catch (ScalarConverter::ImpossibleConversionException &e) {
    std::cout << "char: impossible" << std::endl;
  }
  ScalarConverter::printInt(value);
  ScalarConverter::printFloat(value);
  ScalarConverter::printDouble(value);
}

void ScalarConverter::treatItLikeDouble(const std::string &value) {
  try {
    double d = ScalarConverter::parseDouble(value);
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
      throw ScalarConverter::ImpossibleConversionException();
    char c = static_cast<char>(d);
    ScalarConverter::printChar(c);
  } catch (ScalarConverter::ImpossibleConversionException &e) {
    std::cout << "char: impossible" << std::endl;
  }
  ScalarConverter::printInt(value);
  ScalarConverter::printFloat(value);
  ScalarConverter::printDouble(value);
}

void ScalarConverter::printChar(char c) {
  std::cout << "char: ";
  if (isprint(c))
    std::cout << "'" << c << "'";
  else std::cout << "Non displayable";
  std::cout << std::endl;
}

void ScalarConverter::printInt(const std::string &value) {
  try {
    int i = ScalarConverter::parseInt(value);
    std::cout << "int: " << i << std::endl;
  } catch (ScalarConverter::ImpossibleConversionException &e) {
    std::cout << "int: " << "impossible" << std::endl;
  }
}

void ScalarConverter::printFloat(const std::string &value) {
  try {
    float f = parseFloat(value);
    std::stringstream ss;
    ss << f;
    std::string str = ss.str();

    if (str.find('.') == std::string::npos) {
        str += ".0";
    }
    std::cout << "float: " << str << "f" << std::endl;
  } catch(ScalarConverter::ImpossibleConversionException &e) {
    std::cout << "float: impossible" << std::endl;
  }
}

void ScalarConverter::printDouble(const std::string &value) {
  try {
    double d = parseDouble(value);

    std::stringstream ss;
    ss << d;
    std::string str = ss.str();

    if (str.find('.') == std::string::npos) {
        str += ".0";
    }
    std::cout << "double: " << str << std::endl;
  } catch(ScalarConverter::ImpossibleConversionException &e) {
    std::cout << "double: impossible" << std::endl;
  }
}

int ScalarConverter::parseInt(const std::string &value) {
  long res = std::strtol(value.c_str(), nullptr, 10);
  if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
    throw ScalarConverter::ImpossibleConversionException();
  return static_cast<int>(res);
}

float ScalarConverter::parseFloat(const std::string &value) {
  float res = std::strtof(value.c_str(), nullptr);
  if (errno == ERANGE)
    throw ScalarConverter::ImpossibleConversionException();
  return res;
}

double ScalarConverter::parseDouble(const std::string &value) {
  double res = std::strtod(value.c_str(), nullptr);
  if (errno == ERANGE)
    throw ScalarConverter::ImpossibleConversionException();
  return res;
}

