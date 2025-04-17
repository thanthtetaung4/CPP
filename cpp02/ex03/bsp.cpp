/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:00:15 by taung             #+#    #+#             */
/*   Updated: 2025/04/17 12:59:47 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Already good
Fixed abs(Fixed numb) {
	if (numb.toFloat() < 0)
		return (numb * -1);
	return (numb);
}

// Already good
Fixed	getArea(Point p1, Point p2, Point p3) {
	Fixed area = (abs(p1.getX() * (p2.getY() - p3.getY())
					+ p2.getX() * (p3.getY() - p1.getY())
					+ p3.getX() * (p1.getY() - p2.getY()))) / 2;
	return (area);
}

// New helper: Check if point is on the line segment between p1 and p2
bool isOnEdge(Point const p1, Point const p2, Point const point) {
	Fixed area = getArea(p1, p2, point);
	if (area != Fixed(0))
		return false; // not colinear

	// additionally check if point is between p1 and p2
	Fixed minX = (p1.getX() < p2.getX()) ? p1.getX() : p2.getX();
	Fixed maxX = (p1.getX() > p2.getX()) ? p1.getX() : p2.getX();
	Fixed minY = (p1.getY() < p2.getY()) ? p1.getY() : p2.getY();
	Fixed maxY = (p1.getY() > p2.getY()) ? p1.getY() : p2.getY();

	if (point.getX() < minX || point.getX() > maxX || point.getY() < minY || point.getY() > maxY)
		return false; // outside the segment

	return true; // colinear and between p1 and p2
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	// If point is on any edge or matches any vertex, return false
	if (isOnEdge(a, b, point) || isOnEdge(b, c, point) || isOnEdge(a, c, point))
		return false;

	if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
		(point.getX() == b.getX() && point.getY() == b.getY()) ||
		(point.getX() == c.getX() && point.getY() == c.getY()))
		return false;

	// Regular inside check
	if (getArea(a,b,c) == (getArea(a,b,point) + getArea(b,c,point) + getArea(a,c,point)))
		return true;
	return false;
}
