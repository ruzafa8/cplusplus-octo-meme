#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &other);
        ~ScavTrap(void);

        ScavTrap    &operator=(ScavTrap const &other);

        void        guardGate(void);
    private:
        ScavTrap();
};

#endif