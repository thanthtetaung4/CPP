/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:20:43 by taung             #+#    #+#             */
/*   Updated: 2025/11/26 23:46:04 by taung            ###   ########.fr       */
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
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat	b("tayza", 150);
		b.gradeUp();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat	b("tayza", 1);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat	b("tayza", 1);
		b.gradeDown();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat b("b", 1);
		AForm *shr = new ShrubberyCreationForm("shr");
		AForm *shr2 = new ShrubberyCreationForm("shr");
		*shr2 = *shr;
		shr->execute(b);
		delete shr;
		delete shr2;
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat b("b", 1);
		AForm *shr = new PresidentialPardonForm("aoo");
		AForm *shr2 = new PresidentialPardonForm("aoo");
		*shr2 = *shr;
		shr->execute(b);
		b.executeForm(*shr);
		delete shr;
		delete shr2;
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat b("b", 1);
		AForm *shr = new RobotomyRequestForm("aoo");
		AForm *shr2 = new RobotomyRequestForm("aoo");
		*shr2 = *shr;
		shr->execute(b);
		b.executeForm(*shr);
		delete shr;
		delete shr2;
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}
	std::cout << "========================================" << std::endl;
	AForm *shr = new RobotomyRequestForm("aoo");
	try {
		Bureaucrat b("b", 1);
		b.signForm(*shr);
		b.signForm(*shr);
		shr->execute(b);
		b.executeForm(*shr);
		delete(shr);
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
		delete(shr);
	}


	try {
		Intern	in;
		Bureaucrat b("bob", 1);
		AForm *f1 = in.makeForm("robotomy request", "target1");
		AForm *f2 = in.makeForm("shrubbery creation", "target2");
		AForm *f3 = in.makeForm("presidential pardon", "target3");
		f1->execute(b);
		f2->execute(b);
		b.executeForm(*f3);
		delete f1;
		delete f2;
		delete f3;
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}
}
