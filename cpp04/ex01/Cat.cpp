/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:36 by taung             #+#    #+#             */
/*   Updated: 2025/05/12 21:21:27 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

std::string	Cat::whatAmI(void) const {
	return ("Cat");
}

Cat::Cat(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
	this->brain = new Brain();
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
	delete this->brain;
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
	// std::cout << "I have an idea " << this->brain << std::endl;
}

