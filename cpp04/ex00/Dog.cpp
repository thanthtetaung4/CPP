/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:42 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 13:51:30 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

std::string	Dog::whatAmI(void) const {
	return ("Dog");
}

Dog::Dog(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(std::string type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}
