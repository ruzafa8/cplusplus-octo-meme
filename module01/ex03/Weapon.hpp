#include "Weapon.hpp"

class Weapon {

    public:
        Weapon();
        ~Weapon(void);

        std::string getType(void) const;
        void setType(std::string type);

    private:
        std::string type;
}