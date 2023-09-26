#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testExample() {
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void testWrongExample() {
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();
	std::cout << i->getType() << std::endl;
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
}

void testArray() {
	const Animal *animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
}

int main()
{
	testExample();
	std::cout << std::endl;
	testWrongExample();
	std::cout << std::endl;
	testArray();

	return 0;
}