/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:40:37 by taung             #+#    #+#             */
/*   Updated: 2025/08/26 21:21:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern {
	public:
		Intern(void);
		Intern(Intern& other);
		Intern& operator=(Intern& other);
		~Intern();
		AForm*	makeForm(std::string formName, std::string targetName);

};

# endif
