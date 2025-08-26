/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:20:43 by taung             #+#    #+#             */
/*   Updated: 2025/08/26 21:41:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Intern.hpp"

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
		AForm *shr = new ShrubberyCreationForm("shr");
		AForm *shr2 = new ShrubberyCreationForm("shr");
		*shr2 = *shr;
		shr->execute(b);
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}

	try {
		Bureaucrat b("b", 1);
		AForm *shr = new PresidentialPardonForm("aoo");
		AForm *shr2 = new PresidentialPardonForm("aoo");
		*shr2 = *shr;
		shr->execute(b);
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}

	try {
		Bureaucrat b("b", 1);
		AForm *shr = new RobotomyRequestForm("aoo");
		AForm *shr2 = new RobotomyRequestForm("aoo");
		*shr2 = *shr;
		shr->execute(b);
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}

	try {
		Bureaucrat b("b", 1);
		std::string	forms[4] = {"robotomy request", "shrubbery creation", "presidential pardon", "random form"};
		AForm*	validForms[4] = {NULL, NULL, NULL, NULL};
		Intern	i;
		for (int j = 0; j < 3; j++) {
			validForms[j] = i.makeForm(forms[j], "random target");
			if (validForms[j])
				validForms[j]->execute(b);
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}
}
