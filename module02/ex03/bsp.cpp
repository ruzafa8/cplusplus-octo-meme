#include "Point.hpp"

Fixed abs(Fixed const &n) {
	return (n >= 0 ? n : n * -1);
}

Fixed triangleArea(Point const a, Point const b, Point const c) {
	return abs(
		a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY())
	) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed const abc = triangleArea(a, b, c);
	Fixed const abp = triangleArea(a, b, point);
	Fixed const bcp = triangleArea(b, c, point);
	Fixed const cap = triangleArea(c, a, point);
	if (abc == 0 || abp == 0 || bcp == 0 || cap == 0) {
		return false;
	}
	return (abc == abp + bcp + cap);
}