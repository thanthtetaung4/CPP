/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:20:43 by taung             #+#    #+#             */
/*   Updated: 2025/11/26 15:55:00 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void){
	try {
		Bureaucrat	b("tayza", 150);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat	b("tayza", 150);
		std::cout << b << std::endl;
		b.gradeUp();
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat	b("tayza", 1);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat	b("tayza", 1);
		std::cout << b << std::endl;
		b.gradeDown();
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Form	f("form1", 1, 1);
		Bureaucrat b("tayza", 2);
		b.signForm(f);
		std::cout << b << std::endl << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Form	f("form1", 150, 1);
		Bureaucrat b("tayza", 1);
		b.signForm(f);
		std::cout << b << std::endl << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
