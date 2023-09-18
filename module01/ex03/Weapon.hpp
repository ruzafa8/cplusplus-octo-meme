#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon {

    public:
        Weapon(void);
		Weapon(std::string type);
        ~Weapon(void);

        const std::string &getType(void);
        void setType(std::string type);

    private:
        std::string type;
};

#endif