#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[constructor - Dog] default constructor called" << std::endl;
	AAnimal::type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat const &other): AAnimal(other) {
	std::cout << "[constructor - Dog] copy constructor called" << std::endl;
	brain = new Brain();
	*this = other;
}

Cat::~Cat() {
	std::cout << "[destructor - Dog] destructor called" << std::endl;
	delete brain;
}

Cat	&Cat::operator=(Cat const &other) {
	std::cout << "[operator - Dog] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

Brain	*Cat::getBrain(void) const {
	return (brain);
}

void	Cat::makeSound(void) const {
	std::cout << "Miauuuuuu" << std::endl;
}