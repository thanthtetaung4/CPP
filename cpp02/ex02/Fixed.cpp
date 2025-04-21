/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:57 by taung             #+#    #+#             */
/*   Updated: 2025/04/15 12:40:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed(void) {
	// std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;
	if (this != &other) {
		// this->RawBits = other.getRawBits();
		*this = other;
	}
}

Fixed::Fixed(const int i) {
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = i << this->_fractional;
}

Fixed::Fixed(const float f) {
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(f * (1 << this->_fractional));
}

Fixed::~Fixed() {
// std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_rawBits = other.getRawBits();
	}
	return(*this);
}

bool	Fixed::operator>(const Fixed& other) const{
	// std::cout << "Greater than operator called" << std::endl;
	if (this != &other) {
		return (this->toFloat() > other.toFloat());
	}
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const{
	// std::cout << "Less than operator called" << std::endl;
	if (this != &other) {
		return (this->toFloat() < other.toFloat());
	}
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const{
	// std::cout << "Greater than equal operator called" << std::endl;
	if (this != &other) {
		return (this->toFloat() >= other.toFloat());
	}
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const{
	// std::cout << "Less than equal operator called" << std::endl;
	if (this != &other) {
		return (this->toFloat() <= other.toFloat());
	}
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const{
	// std::cout << "Equal operator called" << std::endl;
	if (this != &other) {
		return (this->toFloat() == other.toFloat());
	}
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const{
	// std::cout << "Not equal operator called" << std::endl;
	if (this != &other) {
		return (this->toFloat() != other.toFloat());
	}
	return (false);
}

Fixed	Fixed::operator+(const Fixed& other) const{
	// std::cout << "+ operator called" << std::endl;
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const{
	// std::cout << "- operator called" << std::endl;
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const{
	// std::cout << "* operator called" << std::endl;
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const{
	// std::cout << "/ operator called" << std::endl;
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++() // prefix
{
	++this->_rawBits;
	return *this;
}

Fixed Fixed::operator++(int) // postfix
{
	Fixed result = *this;
	++this->_rawBits;
	return result;
}

Fixed& Fixed::operator--() // prefix
{
	--this->_rawBits;
	return *this;
}

Fixed Fixed::operator--(int) // postfix
{
	Fixed result = *this;
	--this->_rawBits;
	return result;
}

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	// std::cout << "toFloat called" << this->getRawBits() << std::endl;
	return (((float)this->_rawBits / (1 << this->_fractional)));

}

int	Fixed::toInt(void) const {
	// std::cout << "toInt called" << std::endl;
	return (((int)this->_rawBits >> this->_fractional));
}

Fixed&	Fixed::min(Fixed& p1, Fixed& p2) {
	if (p1 < p2)
		return (p1);
	return (p2);
}

Fixed&	Fixed::min(const Fixed& p1,const Fixed& p2) {
	if (p1 < p2)
		return ((Fixed&)p1);
	return ((Fixed&)p2);
}

Fixed&	Fixed::max(Fixed& p1, Fixed& p2) {
	if (p1 > p2)
		return (p1);
	return (p2);
}

Fixed&	Fixed::max(const Fixed& p1,const Fixed& p2) {
	if (p1 > p2)
		return ((Fixed&)p1);
	return ((Fixed&)p2);
}
