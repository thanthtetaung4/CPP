/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:39:47 by taung             #+#    #+#             */
/*   Updated: 2025/08/19 18:33:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);

	protected:
		void	formAction_(void) const;
};

# endif
