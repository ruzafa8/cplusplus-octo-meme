#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "[constructor] ScavTrap empty created. :D" << std::endl;
    ClapTrap::hitPoints = 100;
    ClapTrap::energyPoints = 50;
    ClapTrap::attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "[constructor] ScavTrap " << name << " created. :D" << std::endl;
    ClapTrap::hitPoints = 100;
    ClapTrap::energyPoints = 50;
    ClapTrap::attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj) {
    std::cout << "[copy constructor] ScavTrap " << name << " created. :D" << std::endl;
    *this = obj;
}

ScavTrap::~ScavTrap() {
    std::cout << "[destructor] ScavTrap " << ClapTrap::name << " finished his life in your PC memory. );" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj) {
    if (this != &obj) {
        this->name = obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}

void ScavTrap::guardGate(void) {
    std::cout << "[guardGate] ScavTrap " << name << " has entered in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "[attack] ";
    if (this->canDoSomething()) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << this->attackDamage << " points of damage! >:D";
        this->energyPoints--;
    }
    std::cout << std::endl;
}