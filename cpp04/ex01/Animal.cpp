/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:32 by taung             #+#    #+#             */
/*   Updated: 2025/05/07 16:07:35 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::whatAmI(void) const {
	return "Animal";
}

Animal::Animal(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "animal";
}

Animal::Animal(std::string type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal& other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	Animal::printAnimalDetails(void) const {
	std::cout << this->type << std::endl;
}


