/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:00:15 by taung             #+#    #+#             */
/*   Updated: 2025/04/15 13:48:45 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed abs(Fixed numb) {
	if (numb.toFloat() < 0)
		return (numb * -1);
	return (numb);
}

Fixed	getArea(Point p1, Point p2, Point p3) {
	/*
		Area = 1/2 |x1(y2-y3)+x2(y3-y1)+x3(y1-y2)|
	*/
	Fixed area = (abs(p1.getX() * (p2.getY() - p3.getY())
					+ p2.getX() * (p3.getY() - p1.getY())
					+ p3.getX() * (p1.getY() - p2.getY()))) / 2;
	std::cout << "area: " << area << std::endl;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	if (getArea(a,b,c) == (getArea(a,b,point) + getArea(b,c, point) + getArea(a,c,point)))
		return (true);
	return (false);
}
