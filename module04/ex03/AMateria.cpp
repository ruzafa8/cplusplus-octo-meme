#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	std::cout << "[constructor - AMateria] default constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const &other) {
	std::cout << "[constructor - AMateria] copy constructor called" << std::endl;
	*this = other;
}

AMateria::~AMateria() {
	std::cout << "[destructor - AMateria] destructor called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &other) {
	std::cout << "[operator - AMateria] assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

std::string const & AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "Se usó materia de tipo " << type << " contra " << target.getName() << std::endl;
}