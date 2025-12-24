/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:35:08 by taung             #+#    #+#             */
/*   Updated: 2025/12/24 22:25:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span(void) : _N(0) {}

Span::Span(unsigned int N) : _N(N) {
	if (N == 0)
		throw Span::IvalidN();
}

Span::Span(const Span& other) {
	*this = other;
}

Span::~Span() {}

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		this->_N = other._N;
		this->_container = other._container;
	}
	return (*this);
}

void	Span::addNumber(int i) {
	if (this->_N == (unsigned int)this->_container.size())
		throw Span::ContainerIsFull();
	else {
		this->_container.push_back(i);
		std::sort(this->_container.begin(), this->_container.end());
	}
}

/*
** shortestSpan: Finds the smallest difference between any two adjacent numbers
** in the sorted container. Since the container is always kept sorted after each
** insertion, the shortest span will always be between two consecutive elements.
** Iterates through all adjacent pairs and returns the minimum difference.
** Throws NotEnoughElements if less than 2 numbers are stored.
*/
int		Span::shortestSpan(void) {
	if (this->_container.size() < 2)
		throw Span::NotEnoughElements();

	int	ss = this->_container[1] - this->_container[0];
	for (size_t i = 1; i < this->_container.size() - 1; i++) {
		if (ss > (this->_container[i + 1] - this->_container[i]))
			ss = this->_container[i + 1] - this->_container[i];
	}

	return (ss);
}

/*
** longestSpan: Finds the largest difference between any two numbers in the
** container. Since the container is always kept sorted, the longest span is
** simply the difference between the last (largest) and first (smallest) elements.
** Throws NotEnoughElements if less than 2 numbers are stored.
*/
int		Span::longestSpan(void) {
	if (this->_container.size() < 2)
		throw Span::NotEnoughElements();
	return (this->_container.back() - this->_container.front());
}

std::ostream&	operator<<(std::ostream& os, const Span& sp) {
	for (size_t i = 0; i < sp.getContainer().size(); i++) {
		os << "index " << i << " : " << sp.getContainer()[i];
		if (i != sp.getContainer().size() - 1)
			os << std::endl;
	}
	return (os);
}

const std::vector<int>&	Span::getContainer(void) const {
	return (this->_container);
}

unsigned int	Span::getN(void) const {
	return (this->_N);
}
