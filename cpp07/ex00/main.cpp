/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:37:31 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 17:06:00 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"
# include <iostream>

{
	int main( void ) {
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}
}

{
	int main() {
		int	i = 10;
		int	j = 20;

		std::cout << (&i == &min(i,j)) << (&j == &max(i,j)) << std::endl;

		std::cout << i << " , " << j << std::endl;
		swap(i,j);
		std::cout << i << " , " << j << std::endl;

		std::cout << min(i, j) << std::endl;
		std::cout << max(i, j) << std::endl;
	}
}
