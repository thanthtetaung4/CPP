/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:41:04 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 19:39:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cout << "Parameterized AMateria constructor called" << std::endl;
	this->ownedBy = NULL;
}

AMateria::AMateria(void) {
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	std::cout << "Copy Assigment AMateria constructor called" << std::endl;
	if (this != &other) {
		*this = other;
	}
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Destroyed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other) {
	std::cout << "Assigment AMateria operator called" << std::endl;
	(void) other;
	return (*this);
}

void	AMateria::setOwnership(ICharacter *c) {
	this->ownedBy = c;
}

const ICharacter*	AMateria::getOwnership(void) const {
	return (this->ownedBy);
}

std::string const &	AMateria::getType() const {
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}
