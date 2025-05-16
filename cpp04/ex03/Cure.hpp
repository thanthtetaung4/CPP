/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:30:14 by taung             #+#    #+#             */
/*   Updated: 2025/05/16 18:06:04 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"

class	Cure: public AMateria {
	public:
		Cure(void);
		Cure(std::string const &type);
		Cure(Cure &other);
		~Cure(void);
		Cure& operator=(const Cure& other);
		AMateria*	clone() const;
		void	use(ICharacter& target);
};

#endif
