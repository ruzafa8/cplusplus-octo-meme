#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[constructor - Dog] default constructor called" << std::endl;
	Animal::type = "Dog";
}

Dog::Dog(Dog const &other) {
	std::cout << "[constructor - Dog] copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "[destructor - Dog] destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &other) {
	std::cout << "[operator - Dog] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Guau, Guau!!" << std::endl;
}