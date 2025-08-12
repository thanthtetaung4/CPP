/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:21:22 by taung             #+#    #+#             */
/*   Updated: 2025/08/12 16:59:21 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form(void) : _name(0), _isSigned(0), _gradeToSign(150), _gradeToExectue(150){}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExectue(other._gradeToExectue) {}

Form& Form::operator=(const Form& other) {
	if(this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExectue(gradeToExecute) {
	if (gradeToSign < 1) {
		throw Form::GradeTooLowException();
	}
	else if (gradeToSign > 150) {
		throw Form::GradeTooHighException();
	}

	if (gradeToExecute < 1) {
		throw Form::GradeTooLowException();
	}
	else if (gradeToExecute > 150) {
		throw Form::GradeTooHighException();
	}
}

Form::~Form() {
	std::cout << "Form " << this->getName() << " destroyed" << std::endl;
}

const std::string& Form::getName(void) const {
	return (this->_name);
}

const bool& Form::getIsSigned(void) const {
	return (this->_isSigned);
}

const int& Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

const int& Form::getGradeToExectue(void) const {
	return (this->_gradeToExectue);
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeToSign) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_isSigned = true;
	}
}

std::ostream& operator<<(std::ostream &os, const Form f) {
	os << "Form " << f.getName() << " \n\t isSigned: " << f.getIsSigned()
	<< " \n\t\t gradeToSign: " << f.getGradeToSign() << " \n\t\t gradeToExecute: "
	<< f.getGradeToExectue() << std::endl;
	return (os);
}
