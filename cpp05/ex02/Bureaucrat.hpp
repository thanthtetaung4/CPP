/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:50 by taung             #+#    #+#             */
/*   Updated: 2025/08/12 17:44:36 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <exception>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
		bool	checkGrade(int grade);
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat &other);

		// accessors
		const std::string&	getName(void) const;
		const int&			getGrade(void) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Bureaucrat grade is too high";
			}
		};
		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Bureaucrat grade is too low";
			}
		};

		//Increment & Decrement functions
		void	gradeUp();
		void	gradeDown();

		//Sign Func
		void	signForm(AForm& f);

};
std::ostream& operator<<(std::ostream &os, const Bureaucrat b);

# endif
