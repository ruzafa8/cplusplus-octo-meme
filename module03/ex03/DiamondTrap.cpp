#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->name = name;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

unsigned int	DiamondTrap::getCurrentLife(void)
{
	return (FragTrap::hitPoints);
}

unsigned int	DiamondTrap::getEnergy(void)
{
	return (ScavTrap::energyPoints);
}

unsigned int	DiamondTrap::getDamage(void)
{
	return (FragTrap::attackDamage);
}
void DiamondTrap::setDamage(const unsigned int damage)
{
	FragTrap::attackDamage = damage;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "DiamondTrap ClapTrap name: " << ClapTrap::name << std::endl;
}