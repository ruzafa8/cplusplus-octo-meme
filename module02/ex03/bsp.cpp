#include "Point.hpp"

bool bsp(
	Fixed const a,
	Fixed const b,
	Fixed const c,
	Point const point
) {
	Fixed const x = point.getX();
	Fixed const y = point.getY();
	Fixed const result = a * x + b * y + c;
	if (result > 0) {
		return true;
	} else {
		return false;
	}
}