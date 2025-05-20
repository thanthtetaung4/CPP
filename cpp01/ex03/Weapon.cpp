/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:12:46 by taung             #+#    #+#             */
/*   Updated: 2025/05/20 14:36:29 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon(void) {
	std::cout << "Weapon " << this->_type << " destroyed" << std::endl;
}

const	std::string&	Weapon::getType(void) {
	return	(const std::string&)_type;
}

void					Weapon::setType(std::string type) {
	this->_type = type;
}
