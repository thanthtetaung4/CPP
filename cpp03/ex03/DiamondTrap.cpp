/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:10:24 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 13:55:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->FragTrap::_name = "a new DiamondTrap";
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

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

/*
This member function will display both its name and its ClapTrap name.
*/
void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap Name: " << this->_name << std::endl;
	std::cout << "Its ClapTrap Name: " << this->FragTrap::_name << std::endl;
}

const std::string	DiamondTrap::myName(void) const {
	return	("Diamond Trap");
}

const std::string&	DiamondTrap::getDiamondTrapName(void) const {
	return	(this->_name);
}
