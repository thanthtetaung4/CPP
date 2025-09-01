/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:05:46 by taung             #+#    #+#             */
/*   Updated: 2025/09/01 21:08:49 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "ScalarConverter.hpp"

int main(int ac, char **av) {

	std::cout << std::numeric_limits<double>::max() << std::endl;
	if (ac < 2)
		std::cerr << "usage: ./scalar <input> | <inputs>" << std::endl;
	for (int i = 1; i < ac; i++) {
		ScalarConverter::convert(std::string(av[i]));
		i != ac ? std::cout << "==========================================" << std::endl : std::cout << std::endl;
	}
}
