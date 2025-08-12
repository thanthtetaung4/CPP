/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:21:22 by taung             #+#    #+#             */
/*   Updated: 2025/08/12 17:44:43 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(void) : _name(0), _isSigned(0), _gradeToSign(150), _gradeToExectue(150){}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExectue(other._gradeToExectue) {}

AForm& AForm::operator=(const AForm& other) {
	if(this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExectue(gradeToExecute) {
	if (gradeToSign < 1) {
		throw AForm::GradeTooLowException();
	}
	else if (gradeToSign > 150) {
		throw AForm::GradeTooHighException();
	}

	if (gradeToExecute < 1) {
		throw AForm::GradeTooLowException();
	}
	else if (gradeToExecute > 150) {
		throw AForm::GradeTooHighException();
	}
}

AForm::~AForm() {
	std::cout << "Form " << this->getName() << " destroyed" << std::endl;
}

const std::string& AForm::getName(void) const {
	return (this->_name);
}

const bool& AForm::getIsSigned(void) const {
	return (this->_isSigned);
}

const int& AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

const int& AForm::getGradeToExectue(void) const {
	return (this->_gradeToExectue);
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeToSign) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_isSigned = true;
	}
}

std::ostream& operator<<(std::ostream &os, const AForm& f) {
	os << "Form " << f.getName() << " \n\t isSigned: " << f.getIsSigned()
	<< " \n\t\t gradeToSign: " << f.getGradeToSign() << " \n\t\t gradeToExecute: "
	<< f.getGradeToExectue() << std::endl;
	return (os);
}
