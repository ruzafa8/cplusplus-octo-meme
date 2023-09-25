#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(Animal const &other);
		virtual ~Animal(void);

		Animal &operator=(Animal const &other);

		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string type;
};

#endif