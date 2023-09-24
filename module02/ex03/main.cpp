#include <iostream>
#include "Point.hpp"

int main(void)
{
	{
		// Triangle witha a point inside
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 30);
		Point point(1, 1);
		bsp(a, b, c, point)
			? std::cout << "Point is inside" << std::endl
			: std::cout << "Point is outside" << std::endl;
	}
	{
		// Triangle with a point outside
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 30);
		Point point(42, 42);
		bsp(a, b, c, point)
			? std::cout << "Point is inside" << std::endl
			: std::cout << "Point is outside" << std::endl;
	}
	{
		// Triangle with a point on the edge
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 30);
		Point point(0, 0);
		bsp(a, b, c, point)
			? std::cout << "Point is inside" << std::endl
			: std::cout << "Point is outside" << std::endl;
	}
	{
		// Triangle with a point on the edge
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 30);
		Point point(0, 20);
		bsp(a, b, c, point)
			? std::cout << "Point is inside" << std::endl
			: std::cout << "Point is outside" << std::endl;
	}
}