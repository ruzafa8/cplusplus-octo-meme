#include "Character.hpp"

Character::Character() {
	std::cout << "[constructor - Character] default constructor called" << std::endl;
}

Character::Character(std::string const &name): name(name) {
	std::cout << "[constructor - Character] parameter constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(Character const &other) {
	std::cout << "[constructor - Character] copy constructor called" << std::endl;
	*this = other;
}

Character::~Character() {
	std::cout << "[destructor - Character] destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != NULL) {
			delete inventory[i];
		}
	}
}

Character	&Character::operator=(Character const &other) {
	std::cout << "[operator - Character] assignation operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < 4; i++) {
			if (inventory[i] != NULL) {
				delete inventory[i];
			}
			inventory[i] = other.inventory[i] != NULL ? other.inventory[i]->clone() : NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName() const {
	return (name);
}

void Character::equip(AMateria *m) {
	int i = 0;
	while (i < 4 && inventory[i] != NULL) {
		i++;
	}
	if (i < 4) {
		inventory[i] = m;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
		inventory[idx]->use(target);
	}
}

AMateria *Character::getMateriaFromInventory(int idx) {
	if (idx >= 0 && idx < 4) {
		return (inventory[idx]);
	}
	return (NULL);
}