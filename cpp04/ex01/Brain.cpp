/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:21:02 by taung             #+#    #+#             */
/*   Updated: 2025/05/09 17:24:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Default constructor called" << std::endl;
	ideas[100] = {};
}

Brain::Brain(Brain &other) {
	if (this != &other) {
		*this = other;
	}
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (size_t i = 0; i < this->ideas->length(); i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain  destructor called" << std::endl;
}

void		Brain::setIdea(std::string idea, const int index) {
	this->ideas[index] = idea;
}

std::string	Brain::getIdea(const int index) const {
	return (this->ideas[index]);
}
