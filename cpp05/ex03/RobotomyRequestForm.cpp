/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:04:55 by taung             #+#    #+#             */
/*   Updated: 2025/11/26 15:43:49 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: " << this->getName() << " is destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void RobotomyRequestForm::formAction_(void) const {
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}

	int randNumb = std::rand();
	std::cout << randNumb << std::endl;

	if (randNumb % 2 == 0)
		std::cout << "lasjkdhfkjasdghflkasjdhf "
				  << this->getTarget()
				  << " has been robotomized 🤖🤖";
	else
		std::cout << "Robot is not roboting 😵";
}
