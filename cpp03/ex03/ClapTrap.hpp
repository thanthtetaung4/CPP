/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:41 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 11:30:22 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP__
#define __CLAP_TRAP__

#include <iostream>

/*
The reason why I use protected for inheritence is because this is probably like a game
and directly accessing is faster than setter and getter functions calls.
And since I don't need to use public setter and getter functions
the values of the attributes of all the classes happens inside not outside.
Example: if HP is updated it is 200% sure that happens inside the xx-trap
not outside like main.cpp.
*/
class ClapTrap {
	private:
		const virtual std::string	myName(void) const;
	protected:
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
		void		printStatus(void) const;
		std::string	getName(void) const;
		unsigned int			getHP(void) const;
		unsigned int			getEP(void) const;
		int			getDMG(void) const;
		void		setName(std::string name);
		void		setHP(unsigned int amount);
		void		setEP(int amount);
		void		setDMG(int amount);
};

#endif
