#include "Point.hpp"

Point::Point() {}
Point::Point(Point const &src): _x(src._x), _y(src._y) {
}

Point::Point(Fixed const &x, Fixed const &y): _x(x), _y(y){}

Point::~Point() {

}

Point &Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}

Fixed const &Point::getX(void) const {
	return this->_x;
}

Fixed const &Point::getY(void) const {
	return this->_y;
}