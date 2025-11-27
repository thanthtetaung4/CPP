/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:50 by taung             #+#    #+#             */
/*   Updated: 2025/11/03 17:54:42 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <exception>
# include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		bool	_checkGrade(int grade);
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
		class	GradeTooHighException : public std::exception {
			public:
			virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw();
		};
		class	CannotCreateBureaucrat : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		//Increment & Decrement functions
		void	gradeUp();
		void	gradeDown();
};
std::ostream& operator<<(std::ostream &os, const Bureaucrat& b);

# endif
