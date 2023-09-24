#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &other);
        ~ScavTrap(void);

        ScavTrap    &operator=(ScavTrap const &other);

        void        guardGate(void);
        void        attack(const std::string& target);

    private:
        ScavTrap();
};

#endif