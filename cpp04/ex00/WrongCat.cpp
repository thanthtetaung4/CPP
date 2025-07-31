/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:51 by taung             #+#    #+#             */
/*   Updated: 2025/06/06 13:34:53 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

std::string	WrongCat::whatAmI(void) const {
	return ("WrongCat");
}

WrongCat::WrongCat(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(std::string type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
