/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:27:06 by taung             #+#    #+#             */
/*   Updated: 2025/05/16 18:00:37 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __AMATERIA_H__
# define __AMATERIA_H__

# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria &other);
		virtual	~AMateria(void);
		AMateria& operator=(const AMateria &other);
		std::string const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void	use(ICharacter& target);
};

# endif
