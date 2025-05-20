/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:12:52 by taung             #+#    #+#             */
/*   Updated: 2025/05/20 14:43:52 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__
#include "Weapon.hpp"

class HumanB {
	private:
		Weapon		*_weapon;
		std::string	_name;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif
