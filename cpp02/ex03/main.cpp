/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:27:41 by taung             #+#    #+#             */
/*   Updated: 2025/04/17 13:04:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point	a(1,2),b(5,2),c(4,5),point(3,3);
	bsp(c,b,a,point) ? std::cout << "in" << std::endl : std::cout << "out" << std::endl;
	point = Point(1,2);
	bsp(c,b,a,point) ? std::cout << "in" << std::endl : std::cout << "out" << std::endl;
	point = Point(2,3);
	bsp(c,b,a,point) ? std::cout << "in" << std::endl : std::cout << "out" << std::endl;
	return 0;
}
