/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:10:19 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 13:55:25 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DiamondTrap_HPP__
#define __DiamondTrap_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;
		const std::string	myName(void) const;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();
		// using	ScavTrap::attack;
		void		attack(const std::string& target);
		// void		takeDamage(unsigned int amount);
		// void		beRepaired(unsigned int amount);
		// void		printStatus(void) const;
		void		whoAmI(void);
		const std::string&	getDiamondTrapName(void) const;
};

#endif
