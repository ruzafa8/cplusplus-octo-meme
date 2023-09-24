#include "ClapTrap.hpp"

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

bool testConstructor() {
    bool        result;
    std::string name = "Constructor properties";
    startTestMessage(name);
    ClapTrap dummy("Dummy");

    result = nameShouldBe(dummy, "Dummy")
        && damageShouldBe(dummy, 0)
        && lifeShouldBe(dummy, 10)
        && energyShouldBe(dummy, 10);
    endTestMessage(name, result);
    return result;
}

bool testSetDamage() {
    bool        result;
    std::string name = "Set damage";
    startTestMessage(name);
    ClapTrap alex("aruzafa-");

    result = damageShouldBe(alex, 0);
    alex.setDamage(42);
    result = result && damageShouldBe(alex, 42);
    endTestMessage(name, result);
    return result;
}

bool testDamageLife() {
    bool        result;
    std::string name = "Test damage function";
    startTestMessage(name);
    ClapTrap patxi("patxi");

    result = lifeShouldBe(patxi, 10);
    patxi.takeDamage(5);
    result = result && lifeShouldBe(patxi, 5);
    endTestMessage(name, result);
    return result;
}

bool testDamageMoreThanLife() {
    bool        result;
    std::string name = "Test damage function";
    startTestMessage(name);
    ClapTrap patxi("patxi");

    result = lifeShouldBe(patxi, 10);
    patxi.takeDamage(15);
    result = result && shouldBeDead(patxi);
    endTestMessage(name, result);
    return result;
}

bool testDamageAfterDeath() {
    bool        result;
    std::string name = "Test damage function";
    startTestMessage(name);
    ClapTrap patxi("patxi");

    result = lifeShouldBe(patxi, 10);
    patxi.takeDamage(10);
    result = result && shouldBeDead(patxi);
    patxi.takeDamage(15);
    result = result && shouldBeDead(patxi);
    endTestMessage(name, result);
    return result;
}

bool testDamageUntilDeath() {
    bool        result;
    std::string name = "Test damage function";
    startTestMessage(name);
    ClapTrap patxi("patxi");

    result = lifeShouldBe(patxi, 10);
    int i = 0;
    while (patxi.getCurrentLife() > 0 && result) {
        patxi.takeDamage(1);
        result = result && lifeShouldBe(patxi, 10 - ++i);
    }
    result = result && shouldBeDead(patxi);
    endTestMessage(name, result);
    return result;
}

bool testRepair() {
    bool        result;
    std::string name = "Test repair function";
    startTestMessage(name);
    ClapTrap patxi("patxi");

    result = lifeShouldBe(patxi, 10);
    patxi.beRepaired(5);
    result = result && lifeShouldBe(patxi, 15);
    endTestMessage(name, result);
    return result;
}

bool testDamageAndRepair() {
    bool        result;
    std::string name = "Test if we make damage and repair with the same values, the life is the same";
    startTestMessage(name);
    ClapTrap patxi("patxi");

    result = lifeShouldBe(patxi, 10);
    patxi.takeDamage(5);
    patxi.beRepaired(5);
    result = result && lifeShouldBe(patxi, 10);
    endTestMessage(name, result);
    return result;
}

bool testDamageAndRepairAfterDeath() {
    bool        result;
    std::string name = "Test if we try to repair a dead ClapTrap, it doesn't work";
    startTestMessage(name);
    ClapTrap patxi("patxi");

    result = lifeShouldBe(patxi, 10);
    patxi.takeDamage(10);
    result = result && shouldBeDead(patxi);
    patxi.beRepaired(5);
    result = result && shouldBeDead(patxi);
    patxi.beRepaired(5);
    result = result && shouldBeDead(patxi);
    endTestMessage(name, result);
    return result;
}

bool testAttackNoDamage() {
    bool        result;
    std::string name = "Test attack 0 damage";
    startTestMessage(name);
    ClapTrap alex("aruzafa-");
    ClapTrap jose("jarredon");

    result = lifeShouldBe(alex, 10);
    result = result && lifeShouldBe(jose, 10);
    attacksTo(alex, jose);
    result = result && lifeShouldBe(alex, 10);
    result = result && lifeShouldBe(jose, 10);
    endTestMessage(name, result);
    return result;
}

bool testAttack() {
    bool        result;
    std::string name = "Test attack";
    startTestMessage(name);
    ClapTrap alex("aruzafa-");
    ClapTrap jose("jarredon");

    result = lifeShouldBe(alex, 10);
    result = result && lifeShouldBe(jose, 10);
    alex.setDamage(5);
    attacksTo(alex, jose);
    result = result && lifeShouldBe(alex, 10);
    result = result && lifeShouldBe(jose, 5);
    endTestMessage(name, result);
    return result;
}


int main() {
    bool result = testConstructor()
        && testSetDamage()
        && testDamageLife()
        && testDamageMoreThanLife()
        && testDamageAfterDeath()
        && testRepair()
        && testDamageAndRepair()
        && testDamageAndRepairAfterDeath()
        && testAttack();
    std::cout<< std::endl << "[ TEST ] - " << (result ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << std::endl;
    return 0;
}