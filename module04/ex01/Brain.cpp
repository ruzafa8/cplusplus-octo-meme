#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[constructor - Brain] default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "";
    }
}

Brain::Brain(Brain const &other) {
    std::cout << "[constructor - Brain] copy constructor called" << std::endl;
    *this = other;
}

Brain::~Brain() {
    std::cout << "[destructor - Brain] destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &other) {
    std::cout << "[operator - Brain] assignation operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}