/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:41:04 by taung             #+#    #+#             */
/*   Updated: 2025/05/16 17:59:14 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) {
	std::cout << "Parameterized AMateria constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(void) {
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria &other) {
	std::cout << "Copy Assigment AMateria constructor called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Destroyed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other) {
	std::cout << "Assigment AMateria operator called" << std::endl;
	if (this != &other)
	{
		// this->type = other.type;
	}
	return (*this);
}


std::string const &	AMateria::getType() const {
	return (this->type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}
