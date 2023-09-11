#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

Zombie  *zombieHorde(int N, std::string name);

class Zombie {
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);

        void announce(void);
        void setName(std::string name);

    private:
        std::string name;
}

#endif