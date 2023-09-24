#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

# include <string>
# include <iostream>

class ClapTrap {
    public:
        ClapTrap(const ClapTrap &obj);
        ClapTrap(std::string name);
        ~ClapTrap();

        ClapTrap &operator=(ClapTrap const &rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName();
        unsigned int getCurrentLife();
        unsigned int getEnergy();

        unsigned int getDamage();
        void setDamage(const unsigned int damage);

    protected:
        ClapTrap();
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

        bool canDoSomething();
};

#endif
