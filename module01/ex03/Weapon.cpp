#ifndef WEAPON_CPP
# define WEAPON_CPP

# include <iostream>
# include <string>

Weapon::Weapon() {}

Weapon::~Weapon(void) {}

std::string Weapon::getType(void) const {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}

#endif