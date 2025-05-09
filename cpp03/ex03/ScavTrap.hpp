/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:04:20 by taung             #+#    #+#             */
/*   Updated: 2025/05/09 15:39:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAV_TRAP_HPP__
#define __SCAV_TRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	private:
		unsigned int defaultEP;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		printStatus(void) const;
		void		guardGate(void);
		unsigned int	getDefaultEP(void) const;
};

#endif
