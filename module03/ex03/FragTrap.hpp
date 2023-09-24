
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const &other);
        ~FragTrap(void);

        FragTrap    &operator=(FragTrap const &other);

        void        highFivesGuys(void);

    private:
        FragTrap();
};

#endif