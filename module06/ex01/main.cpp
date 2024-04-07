#include "Serializer.hpp"
#include <iostream>

void printData(Data *d) {
	std::cout << "nombre: " << d->name << std::endl;
	std::cout << "edad: " << d->age << std::endl;
	std::cout << "¿Es Rico?: " << (d->isRich ? "Si." : "No.") << std::endl;
}

int main() {
	Data d;
	d.age = 42;
	d.name = "Hantonia";
	d.isRich = true;

	uintptr_t ptr = Serializer::serialize(&d);
	Data *other = Serializer::deserialize(ptr);

	if (&d == other) {
		std::cout << "[OK] - Los punteros son iguales" << std::endl;
	} else {
		std::cout << "[KO] - Los punteros son distintos" << std::endl;
	}
	std::cout << "--- Data original ---" << std::endl;
	printData(&d);
	std::cout << std::endl;
	std::cout << "--- Data deserializada ---" << std::endl;
	printData(other);
}
