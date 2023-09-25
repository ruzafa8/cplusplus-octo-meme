#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(Cat const &other);
		~Cat(void);

		Cat &operator=(Cat const &other);

		void makeSound(void) const;

};

#endif