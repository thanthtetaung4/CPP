/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:31:53 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 14:23:09 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FLAG_TRAP__
#define __FLAG_TRAP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:
		const std::string	myName(void) const;
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();
		void		attack(const std::string& target);
		void		highFivesGuys(void);
};

#endif
