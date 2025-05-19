/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:37:20 by taung             #+#    #+#             */
/*   Updated: 2025/05/19 21:17:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(std::string const &type) : AMateria(type) {
	std::cout << "Parameterized Ice constructor called" << std::endl;
}

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice") {
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
	AMateria *newIce = new Ice(*this);
	std::cout << "cloning " << newIce->getType() << std::endl;
	return (newIce);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

