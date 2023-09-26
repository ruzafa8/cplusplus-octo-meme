#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void testExample(){
	AAnimal *animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
}

void testDeepCopy()
{
	Cat cat1;
	for (int i = 0; i < 100; i++) {
		std::string idea = "idea" + std::to_string(i);
		cat1.getBrain()->setIdea(i, idea);
	}
	Cat cat2(cat1);
	for (int i = 0; i < 100; i+=10)
		std::cout << cat2.getBrain()->getIdea(i) << std::endl;
	cat1.getBrain() != cat2.getBrain() ? std::cout << "Deep copy" << std::endl : std::cout << "Shallow copy" << std::endl;
}

int main()
{
	testExample();
	testDeepCopy();
	// system("leaks main");
	return 0;
}