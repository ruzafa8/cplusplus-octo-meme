#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		virtual ~MateriaSource();

		MateriaSource &operator=(MateriaSource const &other);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

	private:
		AMateria *materia[4];
};

#endif