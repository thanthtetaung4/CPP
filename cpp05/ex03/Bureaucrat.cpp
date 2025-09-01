/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:21 by taung             #+#    #+#             */
/*   Updated: 2025/09/01 17:14:54 by taung            ###   ########.fr       */
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

void	Bureaucrat::signForm(AForm& f) {
	if (f.getIsSigned())
		throw Bureaucrat::FormIsSignedException();
	try {
		f.beSigned(*this);
	} catch (const std::exception& e) {
		std::cout << this->_name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << this->_name << " signed " << f.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) {
	form.execute(*this);
}


Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << this->_name << " killed 💀" << std::endl;
}
