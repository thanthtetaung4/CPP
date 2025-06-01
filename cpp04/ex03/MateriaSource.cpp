/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:53:04 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 14:34:27 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (size_t i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource& other) {
	if (this != &other)
		*this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource& other) {
	if (this != &other) {
		for (size_t i = 0; i < 4; i++) {
			this->materias[i] = other.materias[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
	}
	std::cout << "MateriaSource destroyed" << std::endl;
}

/*
Copies the Materia passed as a parameter and stores it in memory so it can be cloned
later. Like the Character, the MateriaSource can know at most 4 Materias. They
are not necessarily unique.
*/
void	MateriaSource::learnMateria(AMateria* m) {
	for (size_t i = 0; i < 4; i++) {
		if (materias[i] == NULL) {
			// std::cout << "cloning" << std::endl;
			materias[i] = m->clone();
			return;
			// std::cout << m->getType() << " is clonned as " << materias[i]->getType() << std::endl;
		}
	}
}

/*
Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
*/
AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < 4; i++) {
		// std::cout << "materias type :" << this->materias[i]->getType() << " and parameter type :" << type << std::endl;

		if (this->materias[i] && this->materias[i]->getType() == type) {
			return (this->materias[i]->clone());
		}
	}
	return (NULL);
}

