#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	Animal *animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	// test copies are deep copies
	Animal *cat = new Cat();
	Animal *cat2 = new Cat(*static_cast<Cat *>(cat));
	Animal *dog = new Dog();
	Animal *dog2 = new Dog(*static_cast<Dog *>(dog));
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
	return 0;
}