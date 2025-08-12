/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:05:31 by taung             #+#    #+#             */
/*   Updated: 2025/08/11 21:15:32 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include<iostream>

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExectue;

	public:
		Form(void);
		Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		//Exception
		class GradeTooHighException : public std::exception { //will this be ever used??????
			public:
			virtual const char* what() const throw() {
				return "Grade is too high";
			}
		};
		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Grade is too low";
			}
		};

		//Accessors
		const std::string& getName(void) const;
		const bool& getIsSigned(void) const;
		const int& getGradeToSign(void) const;
		const int& getGradeToExectue(void) const;
};
std::ostream& operator<<(std::ostream &os, const Form f);

# endif
