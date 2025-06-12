/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:27:06 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 19:39:40 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __AMATERIA_H__
# define __AMATERIA_H__

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		const std::string	_type;
		ICharacter*	ownedBy;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual	~AMateria(void);
		AMateria& operator=(const AMateria &other);
		std::string const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void	use(ICharacter& target);
		void			setOwnership(ICharacter* c);
		const ICharacter*	getOwnership(void) const;
};

# endif
