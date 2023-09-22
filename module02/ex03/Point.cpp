#include "Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(Point const &src): _x(src._x), _y(src._y) {
}

Point::Point(Fixed const &x, Fixed const &y): _x(x), _y(y){}

Point::~Point() {}

Point &Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}