#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[constructor - Dog] default constructor called" << std::endl;
	Animal::type = "Cat";
}

Cat::Cat(Cat const &other) {
	std::cout << "[constructor - Dog] copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "[destructor - Dog] destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &other) {
	std::cout << "[operator - Dog] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miauuuuuu" << std::endl;
}