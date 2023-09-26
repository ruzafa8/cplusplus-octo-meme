#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "[constructor - Ice] default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other) {
	std::cout << "[constructor - Ice] copy constructor called" << std::endl;
	*this = other;
}

Ice::~Ice() {
	std::cout << "[destructor - Ice] destructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const &other) {
	std::cout << "[operator - Ice] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}