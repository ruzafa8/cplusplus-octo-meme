#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		Character();
		Character(std::string const &name);
		Character(Character const &other);
		virtual ~Character();

		Character &operator=(Character const &other);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		AMateria *getMateriaFromInventory(int idx);
};

#endif