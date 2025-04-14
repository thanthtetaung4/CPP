/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:57 by taung             #+#    #+#             */
/*   Updated: 2025/04/09 18:59:04 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &other) {
		// this->RawBits = other.getRawBits();
		*this = other;
	}
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = i << this->_fractional;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(f * (1 << this->_fractional));
}

Fixed::~Fixed() {
std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_rawBits = other.getRawBits();
	}
	return(*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const{
	// std::cout << "toFloat called" << this->getRawBits() << std::endl;
	return (((float)this->_rawBits / (1 << this->_fractional)));

}

int	Fixed::toInt(void) const {
	// std::cout << "toInt called" << std::endl;
	return (((int)this->_rawBits >> this->_fractional));
}
