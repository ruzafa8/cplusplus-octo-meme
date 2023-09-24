#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
    name("empty"),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::cout << "[constructor] ClapTrap empty created. :D" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
    name(name),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::cout << "[constructor] ClapTrap " << name << " created. :D" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
    *this = obj;
}

ClapTrap::~ClapTrap() {
    std::cout << "[destructor] ClapTrap " << name << " finished his life in your PC memory. );" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &obj) {
    if (this != &obj) {
        this->name = obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "[attack] ";
    if (this->canDoSomething()) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << this->attackDamage << " points of damage! >:D";
        this->energyPoints--;
    }
    std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "[damaged] ";
    if (amount == 0) {
        std::cout << "are you serious trying to make 0 damage to ClapTrap " << name << "?. HAHAHAHA";
    } else if (this->hitPoints == 0) {
        std::cout << "this guy, ClapTrap " << name << ", has already passed out... Don't loose your time with'im!!! ._.";
    } else {
        this->hitPoints = this->hitPoints > amount ? this->hitPoints - amount : 0;
        std::cout << "ClapTrap " << name << " has just received " << amount << " damage. :/" << std::endl;
        if (this->hitPoints == 0) {
            std::cout << "\tHe (or she, or it) has just passed out. RIP in DEP. <3";
        } else {
            std::cout << "\tHe (or she, or it) has got " << this->hitPoints << " life points yet. :P";
        }
    }
    std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "[repairing] ";
    if (this->canDoSomething()) {
        std::cout << "ClapTrap " << name << " repaired itself. >:P" << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "\tHe (or she, or it) has got now " << this->hitPoints << " life points. :P";
    }
    std::cout << std::endl;
}

bool ClapTrap::canDoSomething() {
    if (this->energyPoints == 0) {
        std::cout << "The pour ClapTrap " << name << " cannot do anything 'cause run out of energy points. :(";
        return false;
    }
    if (this->hitPoints == 0) {
        std::cout << "The pour ClapTrap " << name << " cannot do anything 'cause passed out. D:";
        return false;
    }
    return true;
}

std::string ClapTrap::getName() {
    return this->name;
}

unsigned int ClapTrap::getCurrentLife() {
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergy() {
    return this->energyPoints;
}

unsigned int ClapTrap::getDamage() {
    return this->attackDamage;
}

void ClapTrap::setDamage(const unsigned int damage) {
    this->attackDamage = damage;
}
