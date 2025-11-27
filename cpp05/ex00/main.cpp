/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:20:43 by taung             #+#    #+#             */
/*   Updated: 2025/11/26 15:19:50 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"

int	main(void){
	try {
		Bureaucrat	b("john1", 150);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "=========================================" << std::endl;
	try {
		Bureaucrat	b("john2", 1);
		std::cout << b << std::endl;
		b.gradeUp();
		// std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "=========================================" << std::endl;
	try {
		Bureaucrat	b("john3", 1);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "=========================================" << std::endl;
	try {
		Bureaucrat	b("john4", 150);
		std::cout << b << std::endl;
		b.gradeDown();
		// std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
