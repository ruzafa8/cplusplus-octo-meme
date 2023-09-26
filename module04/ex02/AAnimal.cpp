#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "[constructor - AAnimal] default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) {
	std::cout << "[constructor - AAnimal] copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal() {
	std::cout << "[destructor - AAnimal] destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &other) {
	std::cout << "[operator - AAnimal] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	AAnimal::makeSound(void) const {
	std::cout << "._." << std::endl;
}

std::string	AAnimal::getType(void) const {
	return (this->type);
}