/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:30:14 by taung             #+#    #+#             */
/*   Updated: 2025/05/16 18:06:08 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"

class	Ice : public AMateria{
	public:
		Ice(void);
		Ice(std::string const &type);
		Ice(Ice& other);
		~Ice(void);
		Ice& operator=(const Ice& other);
		AMateria*	clone() const;
		void	use(ICharacter& target);
};

#endif
