#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const &other);
		virtual ~AAnimal(void);

		AAnimal &operator=(AAnimal const &other);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

	protected:
		std::string type;
};

#endif