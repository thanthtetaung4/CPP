/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:42 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 13:15:09 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

std::string	Dog::whatAmI(void) const {
	return ("Dog");
}

Dog::Dog(void) {
	std::cout << "Default " << whatAmI() << " Constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(std::string type) : AAnimal(type) {
	std::cout << "Parameterised " << whatAmI() << " Constructor called" << std::endl;
	this->type = type;
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Copy " << whatAmI() << " Constructor called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
		// *this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	Brain	*tmp;

	std::cout << whatAmI() << " Assigment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		tmp = this->brain;
		delete tmp;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << whatAmI() << " " << this->type << " Destroyed 😢" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
	// std::cout << "I have an idea " << this->brain << std::endl;
}

std::string	Dog::think(int index) const {
	return (this->brain->getIdea(index));
}

void	Dog::ideate(int index, std::string idea) {
	this->brain->setIdea(idea, index);
}

const Brain*	Dog::getBrain() const {
	return (this->brain);
}
