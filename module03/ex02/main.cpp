#include "FragTrap.hpp"

void attacksTo(FragTrap & a, FragTrap & b) {
    a.attack(b.getName());
    b.takeDamage(a.getDamage());
}

void startTestMessage(std::string name) {
    std::cout << "[ TEST ] - " << name << std::endl;
}

void endTestMessage(std::string name, bool result) {
    std::cout << "[ TEST ] - " << name << " " << (result ? "PASSED" : "FAILED") << std::endl << std::endl;
}

bool nameShouldBe(FragTrap &c, std::string name) {
    return c.getName() == name;
}

bool damageShouldBe(FragTrap &c, unsigned int damage) {
    return c.getDamage() == damage;
}

bool lifeShouldBe(FragTrap &c, unsigned int life) {
    return c.getCurrentLife() == life;
}

bool energyShouldBe(FragTrap &c, unsigned int energy) {
    return c.getEnergy() == energy;
}

bool shouldBeDead(FragTrap &c) {
    return c.getCurrentLife() == 0;
}

bool testFragTrapDefaultValues() {
    FragTrap dummy("Dummy");
    return nameShouldBe(dummy, "Dummy")
        && damageShouldBe(dummy, 20)
        && lifeShouldBe(dummy, 100)
        && energyShouldBe(dummy, 50);
}

bool testFragTrapCopyConstructor() {
    bool        result;
    FragTrap dummy("Dummy");

    dummy.setDamage(42);
    FragTrap copy(dummy);

    result = nameShouldBe(copy, "Dummy")
        && damageShouldBe(copy, 42)
        && lifeShouldBe(copy, 100)
        && energyShouldBe(copy, 50);
    return result;
}

bool testAssignmentOperator() {
    bool        result;
    FragTrap dummy("Dummy");

    dummy.setDamage(42);
    FragTrap copy = dummy;

    result = nameShouldBe(copy, "Dummy")
        && damageShouldBe(copy, 42)
        && lifeShouldBe(copy, 100)
        && energyShouldBe(copy, 50);
    return result;
}

bool testHighFivesGuys() {
	FragTrap dummy("Dummy");
	dummy.highFivesGuys();
	return true;
}

int main() {
    std::string name = "Test ScapTrap default values";
    bool result;

    startTestMessage(name);
    result = testFragTrapDefaultValues();
    endTestMessage(name, result);

    name = "Test ScapTrap copy constructor";
    startTestMessage(name);
    result = result && testFragTrapCopyConstructor();
    endTestMessage(name, result);

    name = "Test ScapTrap assignment operator";
    startTestMessage(name);
    result = result && testAssignmentOperator();
    endTestMessage(name, result);

	name = "Test ScapTrap highFivesGuys";
	startTestMessage(name);
	result = result && testHighFivesGuys();
	endTestMessage(name, result);

    std::cout << std::endl << "[ TEST ] - " << (result ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << std::endl;
    return 0;
}