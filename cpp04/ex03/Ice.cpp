/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:37:20 by taung             #+#    #+#             */
/*   Updated: 2025/05/16 17:59:03 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(std::string const &type) : AMateria(type) {
	std::cout << "Parameterized Ice constructor called" << std::endl;
}

Ice::Ice(void) : AMateria() {
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(Ice &other) : AMateria(other) {
	std::cout << "Copy Assigment Ice constructor called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
}

Ice::~Ice(void) {
	std::cout << "Ice Destroyed" << std::endl;
}

Ice& Ice::operator=(const Ice &other) {
	std::cout << "Assigment Ice operator called" << std::endl;
	if (this != &other)
	{
		// this->type = other.type;
	}
	return (*this);
}

AMateria*	Ice::clone() const {
	return ((AMateria*)this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

