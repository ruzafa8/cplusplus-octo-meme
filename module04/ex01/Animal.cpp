#include "Animal.hpp"

Animal::Animal() {
	std::cout << "[constructor - Animal] default constructor called" << std::endl;
}

Animal::Animal(Animal const &other) {
	std::cout << "[constructor - Animal] copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << "[destructor - Animal] destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &other) {
	std::cout << "[operator - Animal] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	Animal::makeSound(void) const {
	std::cout << "._." << std::endl;
}

std::string	Animal::getType(void) const {
	return (this->type);
}