/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:32 by taung             #+#    #+#             */
/*   Updated: 2025/06/06 15:10:31 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

std::string AAnimal::whatAmI(void) const {
	return "Animal";
}

AAnimal::AAnimal(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "animal";
}

AAnimal::AAnimal(std::string type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal& other) {
	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	AAnimal::printAnimalDetails(void) const {
	std::cout << this->type << std::endl;
}

std::string	AAnimal::getType(void) const {
	return (this->type);
}

void		AAnimal::setType(std::string type) {
	this->type = type;
}

void	AAnimal::makeSound(void) const {
	std::cout << "inaudible animal sound" << std::endl;
}

