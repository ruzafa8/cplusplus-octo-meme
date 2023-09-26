#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << "[constructor - WrongCat] default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other) {
    std::cout << "[constructor - WrongCat] copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat(void) {
    std::cout << "[destructor - WrongCat] destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &other) {
    std::cout << "[operator - WrongCat] assignation operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return (*this);
}

void	WrongCat::makeSound(void) const {
    std::cout << "WrongCat sound" << std::endl;
}