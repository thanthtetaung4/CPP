/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:41:20 by taung             #+#    #+#             */
/*   Updated: 2025/04/15 12:41:00 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
#define __POINT_H__
#include "Fixed.hpp"

/*
• Public members:
◦ A default constructor that initializes x and y to 0.
◦ A constructor that takes two constant floating-point numbers as parameters.
	It initializes x and y with those parameters.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ Anything else useful.
*/

class Point {
	private:
		Fixed	_x;
		Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& other);
		Point&	operator=(const Point& other);
		~Point(void);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif
