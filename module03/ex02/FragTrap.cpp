
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "[constructor] FragTrap empty created. :D" << std::endl;
    ClapTrap::hitPoints = 100;
    ClapTrap::energyPoints = 50;
    ClapTrap::attackDamage = 20;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "[constructor] FragTrap " << name << " created. :D" << std::endl;
    ClapTrap::hitPoints = 100;
    ClapTrap::energyPoints = 50;
    ClapTrap::attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj) {
    std::cout << "[copy constructor] FragTrap " << name << " created. :D" << std::endl;
    *this = obj;
}

FragTrap::~FragTrap() {
    std::cout << "[destructor] FragTrap " << ClapTrap::name << " finished his life in your PC memory. );" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &obj) {
    if (this != &obj) {
        this->name = obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "[highFivesGuys] FragTrap " << name << " is asking for high fives. :<3>" << std::endl;
}