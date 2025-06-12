/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:37:32 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 19:22:36 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure") {
	std::cout << "Copy Assigment Cure constructor called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
}

Cure::~Cure(void) {
	std::cout << "Cure Destroyed" << std::endl;
}

Cure& Cure::operator=(const Cure &other) {
	std::cout << "Assigment Cure operator called" << std::endl;
	(void) other;
	return (*this);
}

AMateria*	Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
