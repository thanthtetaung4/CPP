/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:27:41 by taung             #+#    #+#             */
/*   Updated: 2025/04/14 14:05:48 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// int main( void ) {
// 	Fixed const a( 10.5f );
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d;
// 	Fixed e(10.5f);
// 	Fixed f(20.5f);
// 	int i = 1;
// 	int j = 2;

// 	std::cout << "a is " << d << std::endl;
// 	std::cout << "e + f is " << (e + f) << std::endl;
// 	std::cout << "e - f is " << (e - f) << std::endl;
// 	std::cout << "e * f is " << (e * f) << std::endl;
// 	std::cout << "f / e is " << (f / e) << std::endl;
// 	std::cout << (a.toFloat() < b.toFloat()) << std::endl;
// 	std::cout << (a.toFloat() > b.toFloat()) << std::endl;

// 	std::cout << (a.toInt() <= b.toInt()) << std::endl;
// 	std::cout << (a.toInt() >= b.toInt()) << std::endl;

// 	std::cout << (i > j) << std::endl;
// 	std::cout << (i < j) << std::endl;
// 	return 0;
// }

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
