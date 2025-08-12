/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:20:43 by taung             #+#    #+#             */
/*   Updated: 2025/08/11 21:11:02 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void){
	try {
		Bureaucrat	b("name", 150);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("name", 150);
		b.gradeUp();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("name", 1);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("name", 1);
		b.gradeDown();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	f("form1", false, 10, 1);
		std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
