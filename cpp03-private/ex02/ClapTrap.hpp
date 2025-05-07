/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:41 by taung             #+#    #+#             */
/*   Updated: 2025/05/06 14:08:34 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP__
#define __CLAP_TRAP__

#include <iostream>

/*
When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it regains <amount> hit points. Attacking and repairing
each cost 1 energy point. Of course, ClapTrap can’t do anything if it has no hit points or
energy points left. However, since these exercises serve as an introduction, the ClapTrap
instances should not interact directly with one another, and the parameters will not refer
to another instance of ClapTrap.
*/
class ClapTrap {
	private:
		std::string	_name;
		unsigned int			_HP;
		unsigned int			_EP;
		int			_DMG;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void) const;
		unsigned int			getHP(void) const;
		unsigned int			getEP(void) const;
		int			getDMG(void) const;
		void		printStatus(void) const;
		void		setName(std::string name);
		void		setHP(unsigned int amount);
		void		setEP(int amount);
		void		setDMG(int amount);

};

#endif
