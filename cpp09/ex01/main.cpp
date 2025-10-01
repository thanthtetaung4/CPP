/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:47:40 by taung             #+#    #+#             */
/*   Updated: 2025/10/01 15:17:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"
# include <string.h>

int	main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "err: at least two arguments needed" << std::endl;
		return (1);
	} else {
		RPN rpn(av[1]);
		if (rpn.getEqueation() != "") {
			std::cout << "RPN equation: " << rpn.getEqueation() << std::endl;
			std::cout << "RPN: " << rpn.exec() << std::endl;
		}
	}
}
