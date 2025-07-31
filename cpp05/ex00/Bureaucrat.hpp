/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:50 by taung             #+#    #+#             */
/*   Updated: 2025/07/31 18:59:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
		bool	checkGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "GradeTooHigh";
				}
			};

};
std::ostream& operator<<(std::ostream &os, const Bureaucrat b);

# endif
