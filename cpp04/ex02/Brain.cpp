/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:40:25 by taung             #+#    #+#             */
/*   Updated: 2025/05/07 21:03:32 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Default Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy Brain Constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain Assigment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < this->ideas->length(); i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

void		Brain::setIdea(std::string idea, int ideaNumber) {
	this->ideas[ideaNumber] = idea;
}

std::string	Brain::getIdea(int ideaNumber) const {
	return (this->ideas[ideaNumber]);
}

std::string*	Brain::getIdeas(void) {
	return (this->ideas);
}

Brain::~Brain() {
	std::cout << "Brain Destroyed 😢" << std::endl;
}
