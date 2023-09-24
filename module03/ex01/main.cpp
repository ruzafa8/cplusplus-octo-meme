#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void attacksTo(ClapTrap & a, ClapTrap & b) {
    a.attack(b.getName());
    b.takeDamage(a.getDamage());
}

void startTestMessage(std::string name) {
    std::cout << "[ TEST ] - " << name << std::endl;
}

void endTestMessage(std::string name, bool result) {
    std::cout << "[ TEST ] - " << name << " " << (result ? "PASSED" : "FAILED") << std::endl << std::endl;
}

bool nameShouldBe(ClapTrap &c, std::string name) {
    return c.getName() == name;
}

bool damageShouldBe(ClapTrap &c, unsigned int damage) {
    return c.getDamage() == damage;
}

bool lifeShouldBe(ClapTrap &c, unsigned int life) {
    return c.getCurrentLife() == life;
}

bool energyShouldBe(ClapTrap &c, unsigned int energy) {
    return c.getEnergy() == energy;
}

bool shouldBeDead(ClapTrap &c) {
    return c.getCurrentLife() == 0;
}

bool testScapTrapDefaultValues() {
    ScavTrap dummy("Dummy");
    return nameShouldBe(dummy, "Dummy")
        && damageShouldBe(dummy, 20)
        && lifeShouldBe(dummy, 100)
        && energyShouldBe(dummy, 50);
}

bool testScapTrapCopyConstructor() {
    bool        result;
    ScavTrap dummy("Dummy");

    dummy.setDamage(42);
    ScavTrap copy(dummy);

    result = nameShouldBe(copy, "Dummy")
        && damageShouldBe(copy, 42)
        && lifeShouldBe(copy, 100)
        && energyShouldBe(copy, 50);
    return result;
}

bool testAssignmentOperator() {
    bool        result;
    ScavTrap dummy("Dummy");

    dummy.setDamage(42);
    ScavTrap copy = dummy;

    result = nameShouldBe(copy, "Dummy")
        && damageShouldBe(copy, 42)
        && lifeShouldBe(copy, 100)
        && energyShouldBe(copy, 50);
    return result;
}

int main() {
    std::string name = "Test ScapTrap default values";
    bool result;

    startTestMessage(name);
    result = testScapTrapDefaultValues();
    endTestMessage(name, result);

    name = "Test ScapTrap copy constructor";
    startTestMessage(name);
    result = result && testScapTrapCopyConstructor();
    endTestMessage(name, result);

    name = "Test ScapTrap assignment operator";
    startTestMessage(name);
    result = result && testAssignmentOperator();
    endTestMessage(name, result);


    std::cout << std::endl << "[ TEST ] - " << (result ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << std::endl;
    return 0;
}