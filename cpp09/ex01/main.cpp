/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:47:40 by taung             #+#    #+#             */
/*   Updated: 2025/12/29 21:32:24 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"
# include <string.h>

int	main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	} else {
		try {
			RPN rpn(av[1]);
			if (rpn.getEqueation() == "")
				throw std::exception();
			std::cout << rpn.exec() << std::endl;
		} catch (...) {
			std::cerr << "Error" << std::endl;
			return (1);
		}
	}
}
