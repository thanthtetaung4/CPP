/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:36 by taung             #+#    #+#             */
/*   Updated: 2025/06/08 18:27:00 by taung            ###   ########.fr       */
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

Cat::Cat(std::string type) : AAnimal(type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
		// *this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
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

std::string	Cat::think(int index) const {
	return (this->brain->getIdea(index));
}

void	Cat::ideate(int index, std::string idea) {
	this->brain->setIdea(idea, index);
}

const Brain*	Cat::getBrain() const {
	return (this->brain);
}
