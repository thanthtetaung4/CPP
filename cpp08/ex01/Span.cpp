/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:35:08 by taung             #+#    #+#             */
/*   Updated: 2025/09/23 16:46:17 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span(void) {
	_N = 0;
}

Span::Span(int N) : _N(N) {
	if (N <= 0)
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

int		Span::shortestSpan(void) {
	int	ss = 0;

	ss = this->_container[1] - this->_container[0];
	for (size_t i = 1; i < (size_t)this->_container.size() - 1; i++) {
		if (ss > (this->_container[i + 1] - this->_container[i]))
			ss = this->_container[i + 1] - this->_container[i];
	}

	return (ss);
}

int		Span::longestSpan(void) {
	return (*(this->_container.end() - 1) - *this->_container.begin());
}

std::ostream&	operator<<(std::ostream& os, Span sp) {
	for (long i = 0; i < (unsigned int)sp.getN(); i++) {
		os << "index " << i << " : " << sp.getContainer()[i];
		(i == (unsigned int)sp.getN() - 1) ? os : os << std::endl;
	}
	return (os);
}

const std::vector<int>&	Span::getContainer(void) const {
	return (this->_container);
}

int		Span::getN(void) const {
	return (this->_N);
}
