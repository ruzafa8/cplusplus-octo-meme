#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamondTrap("DiamondTrap");
	diamondTrap.whoAmI();

	std::cout << "Current life: " << diamondTrap.getCurrentLife() << std::endl;
	std::cout << "Energy: " << diamondTrap.getEnergy() << std::endl;
	std::cout << "Damage: " << diamondTrap.getDamage() << std::endl;

    return 0;
}