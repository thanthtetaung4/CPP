/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:21 by taung             #+#    #+#             */
/*   Updated: 2025/11/26 15:19:26 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	throw	Bureaucrat::CannotCreateBureaucrat();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
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
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::gradeDown() {
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& b) {
	os << "Bureaucrat:\nname: " << b.getName() << "\ngrade: " << b.getGrade();
	return (os);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Bureaucrat grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Bureaucrat grade is too low");
}

const char*	Bureaucrat::CannotCreateBureaucrat::what() const throw(){
	return ("Cannot create bureaucrat with missing values");
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << this->_name << " killed 💀" << std::endl;
}
