#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB(void) {}

void HumanB::attack() {
    if (this->weapon == NULL) {
        std::cout << this->name << " has no weapon" << std::endl;
    } else {
        std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}