#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "[constructor - Cure] default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other) {
	std::cout << "[constructor - Cure] copy constructor called" << std::endl;
	*this = other;
}

Cure::~Cure() {
	std::cout << "[destructor - Cure] destructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const &other) {
	std::cout << "[operator - Cure] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

