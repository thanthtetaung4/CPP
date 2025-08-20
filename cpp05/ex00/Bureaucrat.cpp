/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:21 by taung             #+#    #+#             */
/*   Updated: 2025/08/18 19:07:41 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const {
	return (this->_name);
}

const int&			Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::gradeUp() {
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade++;
}

void	Bureaucrat::gradeDown() {
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade--;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat b) {
	os << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << this->getName() << " is killed" << std::endl;
}
