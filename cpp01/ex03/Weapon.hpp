/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:12:43 by taung             #+#    #+#             */
/*   Updated: 2025/05/30 15:24:07 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__
#include <iostream>

class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(const std::string type);
		~Weapon(void);
		const std::string&	getType(void) const;
		void			setType(const std::string type);
};
#endif
