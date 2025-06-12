/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:30:14 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 19:18:29 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"

class	Cure: public AMateria {
	public:
		Cure(void);
		Cure(const Cure &other);
		~Cure(void);
		Cure& operator=(const Cure& other);
		AMateria*	clone() const;
		void	use(ICharacter& target);
};

#endif
