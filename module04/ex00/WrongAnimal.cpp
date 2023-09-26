#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
    std::cout << "[constructor - WrongAnimal] default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
    std::cout << "[constructor - WrongAnimal] copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "[destructor - WrongAnimal] destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other) {
    std::cout << "[operator - WrongAnimal] assignation operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return (*this);
}

void	WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
    return (this->type);
}