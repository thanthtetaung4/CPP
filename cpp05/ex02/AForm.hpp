/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:05:31 by taung             #+#    #+#             */
/*   Updated: 2025/08/13 00:16:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include<iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExectue;
		const std::string	_target;

	public:
		AForm(void);
		AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute, std::string target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		//Exception
		class GradeTooHighException : public std::exception { //will this be ever used??????
			public:
			virtual const char* what() const throw() {
				return "Form grade is too high";
			}
		};
		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Form grade is too low";
			}
		};

		//Accessors
		// Setters
		const std::string&	getName(void) const;
		const bool&			getIsSigned(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExectue(void) const;
		const std::string&	getTarget(void) const;
		// Getters
		void				setIsSigned(bool isSigned);

		//Functions
		void	beSigned(const Bureaucrat& b);
		void	execute(const Bureaucrat& b) const;
	protected:
		virtual void	formAction() const = 0;
};
std::ostream& operator<<(std::ostream &os, const AForm& f);

# endif
