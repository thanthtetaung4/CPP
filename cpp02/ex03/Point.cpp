/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:27:18 by taung             #+#    #+#             */
/*   Updated: 2025/04/15 12:42:53 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point(void) {
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point(const float x, const float y) {
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::Point(const Point& other) {
	if (this != &other) {
		this->_x.setRawBits(other._x.getRawBits());
		this->_y.setRawBits(other._y.getRawBits());
	}
}

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		this->_x.setRawBits(other._x.getRawBits());
		this->_y.setRawBits(other._y.getRawBits());
	}
	return(*this);
}

Point::~Point(void) {

}

Fixed	Point::getX(void) const {
	return(this->_x);
}

Fixed	Point::getY(void) const {
	return(this->_y);
}
