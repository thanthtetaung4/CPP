/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:08:25 by taung             #+#    #+#             */
/*   Updated: 2025/08/26 21:39:19 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern &other) {
	(void) other;
}

Intern &Intern::operator=(Intern &other) {
	(void) other;
	return (*this);
}

Intern::~Intern() {}

int	getFromNumber(std::string formName) {
	std::string validForms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	for (size_t i = 0; i < formName.length(); ++i)
	{
		formName[i] = std::tolower(static_cast<unsigned char>(formName[i]));
	}

	for (int i = 0; i < 3; i++) {
		if (formName == validForms[i])
			return (i);
	}
	return (3);
}

AForm *Intern::makeForm(std::string formName, std::string targetName) {
	switch (getFromNumber(formName)) {
		case 0:
			return ((AForm*)new RobotomyRequestForm(targetName));
		case 1:
			return ((AForm*)new ShrubberyCreationForm(targetName));
		case 2:
			return ((AForm*)new PresidentialPardonForm(targetName));
		default:
			std::cout << "non existantial form" << std::endl;
			return NULL;
	}
}
