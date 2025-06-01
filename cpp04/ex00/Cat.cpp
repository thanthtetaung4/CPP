/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:36 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 12:13:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

std::string	Cat::whatAmI(void) const {
	return ("Cat");
}

Cat::Cat(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(std::string type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}

