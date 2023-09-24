#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(DiamondTrap const &other);
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap const &other);

		void whoAmI(void);

	private:
		DiamondTrap();
		
		std::string name;
};

#endif