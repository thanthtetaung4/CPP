/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:21 by taung             #+#    #+#             */
/*   Updated: 2025/07/31 19:25:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("unknown"), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	if (this != &other) {
		this->grade = other.grade;
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const {
	return (this->name);
}

const int&			Bureaucrat::getGrade(void) const {
	return (this->grade);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat b) {
	os << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}

Bureaucrat::~Bureaucrat(void) {}
