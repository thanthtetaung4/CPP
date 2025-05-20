/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:12:57 by taung             #+#    #+#             */
/*   Updated: 2025/05/20 14:29:15 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon		_weapon;
		std::string	_name;
	public:
		HumanA(std::string name, Weapon weapon);
		void	attack(void);
};

#endif
