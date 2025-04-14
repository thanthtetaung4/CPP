/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:19:20 by taung             #+#    #+#             */
/*   Updated: 2025/03/28 11:58:54 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	h;

	if (argc == 2) {
		h.complain(argv[1]);
	}
	else
		std::cout << "usage: ./ex06 <complaint level>" << std::endl;
}
