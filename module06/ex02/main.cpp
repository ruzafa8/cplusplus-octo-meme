#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
	srand(time(NULL));
	int random = rand() % 3;

	if (random == 0) {
		return new A();
	} else if (random == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	if (dynamic_cast<B*>(p))
		std::cout << "B";
	if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify(Base &p) {
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "A";
		return;
	} catch (std::exception &e) {}
	try {
		(void) dynamic_cast<B &>(p);
		std::cout << "B";
		return;
	} catch (std::exception &e) {}
	try {
		(void) dynamic_cast<C &>(p);
		std::cout << "C";
		return;
	} catch (std::exception &e) {}
}

int main() {
	{
		Base *p = generate();
		identify(p);
		delete p;
	}
	sleep(1);
	{
		Base *p = generate();
		identify(*p);
		delete p;
	}
}