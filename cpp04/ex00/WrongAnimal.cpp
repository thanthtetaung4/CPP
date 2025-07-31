/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:51 by taung             #+#    #+#             */
/*   Updated: 2025/05/27 21:04:23 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

std::string WrongAnimal::whatAmI(void) const {
	return "WrongAnimal";
}

WrongAnimal::WrongAnimal(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "wronganimal";
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	WrongAnimal::printAnimalDetails(void) const {
	std::cout << this->type << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}

void		WrongAnimal::setType(std::string type) {
	this->type = type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "inaudible animal sound" << std::endl;
}
