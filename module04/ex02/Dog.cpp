#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[constructor - Dog] default constructor called" << std::endl;
	AAnimal::type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog const &other): AAnimal(other) {
	std::cout << "[constructor - Dog] copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "[destructor - Dog] destructor called" << std::endl;
	delete brain;
}

Dog	&Dog::operator=(Dog const &other) {
	std::cout << "[operator - Dog] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Guau, Guau!!" << std::endl;
}

Brain	*Dog::getBrain(void) const {
	return (brain);
}