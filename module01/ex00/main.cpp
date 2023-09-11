#include "Zombie.hpp"

int main(void) {
    Zombie *zombie = newZombie("Pedrito, el Zombie del monticulo");
    zombie->announce();
    delete zombie;
    randomChump("Joselete, el Zombie de la pila");
    return 0;
}