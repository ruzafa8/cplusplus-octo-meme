#include "Fixed.hpp"

Fixed::Fixed(void) : integer(0) {
}

Fixed::Fixed(Fixed const &src) {
    *this = src;
}

Fixed::Fixed(int const integer) {
    this->integer = integer << this->fractionalBits;
}

Fixed::Fixed(float const floating) {
    this->integer = roundf(floating * (1 << this->fractionalBits));
}

Fixed::~Fixed(void) {
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    if (this != &rhs)
        this->integer = rhs.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
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
    return this->integer;
}

void Fixed::setRawBits(int const raw) {
    this->integer = raw;
}

bool Fixed::operator>(Fixed const &rhs) const {
    return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator<(Fixed const &rhs) const {
    return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(Fixed const &rhs) const {
    return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=(Fixed const &rhs) const {
    return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator==(Fixed const &rhs) const {
    return this->toFloat() == rhs.toFloat();
}

bool Fixed::operator!=(Fixed const &rhs) const {
    return this->toFloat() != rhs.toFloat();
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void) {
    this->integer++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->integer--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a.getRawBits() > b.getRawBits() ? a : b;
}
