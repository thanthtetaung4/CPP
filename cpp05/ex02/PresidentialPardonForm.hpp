/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:04:51 by taung             #+#    #+#             */
/*   Updated: 2025/08/13 00:09:31 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name, bool isSigned, std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

	protected:
		void formAction(const Bureaucrat& b);
};

# endif
