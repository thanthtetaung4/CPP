/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:20:43 by taung             #+#    #+#             */
/*   Updated: 2025/08/13 00:24:17 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"

int	main(void){
	try {
		Bureaucrat	b("tayza", 150);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("tayza", 150);
		b.gradeUp();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("tayza", 1);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("tayza", 1);
		b.gradeDown();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("b", 1);
		AForm *shr = new ShrubberyCreationForm("sakura", false, "shr");
		AForm *shr2 = new ShrubberyCreationForm("kura", true, "shr");
		shr->execute(b);
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}
}
