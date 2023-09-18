#ifndef WEAPON_CPP
# define WEAPON_CPP

# include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type): type(type) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}

#endif