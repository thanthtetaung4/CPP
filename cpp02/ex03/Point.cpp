/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:27:18 by taung             #+#    #+#             */
/*   Updated: 2025/05/19 15:20:06 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other) {
	(void)other;
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
