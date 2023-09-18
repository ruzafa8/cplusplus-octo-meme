#include "Fixed.hpp"

Fixed::Fixed(void) : integer(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const integer): {
    std::cout << "Int constructor called" << std::endl;
    this->integer = integer << this->fractionalBits;
}

Fixed::Fixed(float const floating) {
    std::cout << "Float constructor called" << std::endl;
    this->integer = roundf(floating * (1 << this->fractionalBits));
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->integer = rhs.getRawBits();
    return *this;
}

ostream &operator<<(ostream &o, Fixed const &rhs) {
    o << rhs.toFloat();
    return o;
}

float Fixed::toFloat(void) const {
    return (float)this->integer / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const {
    return this->integer >> this->fractionalBits;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->integer;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->integer = raw;
}