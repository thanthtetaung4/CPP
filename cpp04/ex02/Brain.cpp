/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:21:02 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 16:37:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Default constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = "";
	}
}

Brain::Brain(Brain &other) {
	if (this != &other) {
		*this = other;
	}
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (size_t i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain destroyed" << std::endl;
}

void		Brain::setIdea(std::string idea, const int index) {
	if (index > 99 || index < 0) {
		std::cout << index << " is out of range 😵" << std::endl;
		return;
	}
	this->ideas[index] = idea;
}

std::string	Brain::getIdea(const int index) const {
	if (index > 99 || index < 0) {
		std::cout << index << " is out of range 😵" << std::endl;
		return NULL;
	}
	return (this->ideas[index]);
}

