/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:42 by taung             #+#    #+#             */
/*   Updated: 2025/09/24 21:16:15 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <map>
# include "BitcoinExchange.hpp"

int	main(int ac, char *av[]) {
	if (ac == 2) {
		BitcoinExchange	btcx;

		std::cout << "printing the btcx record" << std::endl;
		std::cout << btcx << std::endl;

		btcx.getExchange(av[1]);
	} else {
		std::cerr << "Error: need the input file" << std::endl;
	}
}
