/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:05:31 by taung             #+#    #+#             */
/*   Updated: 2025/11/26 15:23:29 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include<iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExectue;

	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		//Exception
		class GradeTooHighException : public std::exception {
			public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw();
		};

		//Accessors
		const std::string&	getName(void) const;
		const bool&			getIsSigned(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExectue(void) const;

		//Functions
		void	beSigned(const Bureaucrat& b);
};
std::ostream& operator<<(std::ostream &os, const Form f);

# endif
