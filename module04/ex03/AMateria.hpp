#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &other);
		virtual ~AMateria();

		AMateria &operator=(AMateria const &other);

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif