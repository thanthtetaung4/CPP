/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:04:49 by taung             #+#    #+#             */
/*   Updated: 2025/08/13 00:14:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string name, bool isSigned, std::string target)
: AForm(name, false, 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: " << this->getName() << " is destroyed" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	(void)other;
	return (*this);
}

void	PresidentialPardonForm::formAction(const Bureaucrat& b) {}
