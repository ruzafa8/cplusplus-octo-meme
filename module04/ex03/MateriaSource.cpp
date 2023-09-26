#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	*this = other;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (materia[i] != NULL) {
			delete materia[i];
		}
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (materia[i] != NULL) {
				delete materia[i];
			}
			materia[i] = other.materia[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
	int i = 0;
	while (i < 4 && materia[i] != NULL) {
		i++;
	}
	if (i < 4) {
		materia[i] = m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (materia[i] != NULL && materia[i]->getType() == type) {
			return (materia[i]->clone());
		}
	}
	return (NULL);
}