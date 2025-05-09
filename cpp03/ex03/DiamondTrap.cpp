/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:10:24 by taung             #+#    #+#             */
/*   Updated: 2025/05/09 15:51:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->FragTrap::_name = "a new DiamondTrap_clap_name";
	// Have to use like this because of name hiding in C++
	// if the parent and derive share the same member attribute name.
	this->_name = "a new DiamondTrap";
	this->_HP = FragTrap::_HP;
	this->_EP = ScavTrap::getDefaultEP();
	this->_DMG = FragTrap::_DMG;
}

DiamondTrap::DiamondTrap(std::string name){
std::cout << "DiamondTrap name constructor called" << std::endl;
	this->FragTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_HP = FragTrap::_HP;
	this->_EP = ScavTrap::getDefaultEP();
	this->_DMG = FragTrap::_DMG;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
std::cout << "DiamondTrap copy constructor called" << std::endl;
	if (this != &other) {
		*this = other;
	}
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name << " is destroyed" << std::endl;
}

void		DiamondTrap::attack(const std::string& target) {
	std::cout << "DiamondTrap is attacking" << std::endl;
	ScavTrap::attack(target);
}

void		DiamondTrap::takeDamage(unsigned int amount) {
std::cout << "DiamondTrap " << this->_name
	<< " takes " << amount << " points of damage!"
	<<std::endl;
	if (this->_HP < amount)
			this->_HP = 0;
	else
		this->_HP = this->_HP - amount;
}

void		DiamondTrap::beRepaired(unsigned int amount) {
if (this->_HP > 0 && this->_EP > 0) {
	std::cout << "DiamondTrap " << this->_name
	<< " repairs, gaining "
	<< amount << " points of hit points!"
	<<std::endl;
	this->_HP = this->_HP + amount;
	this->_EP = this->_EP - 1;
}
}

void	DiamondTrap::printStatus(void) const {
std::cout << "DiamondTrap : " << this->_name << std::endl
<< "HP       : " << this->_HP << std::endl
<< "EP       : " << this->_EP << std::endl
<< "DMG      : " << this->_DMG << std::endl;
}
/*
This member function will display both its name and its ClapTrap name.
*/
void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap Name: " << this->_name << std::endl;
	std::cout << "Its ClapTrap Name: " << this->FragTrap::_name << std::endl;
}
