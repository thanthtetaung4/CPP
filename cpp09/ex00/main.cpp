/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:42 by taung             #+#    #+#             */
/*   Updated: 2025/12/29 20:28:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "BitcoinExchange.hpp"

int	main(int ac, char *av[]) {
	if (ac == 2) {
		BitcoinExchange	btcx;

		btcx.getExchange(std::string(av[1]));
	} else {
		std::cerr << "Error: could not open file." << std::endl;
	}
	return 0;
}
