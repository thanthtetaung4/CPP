/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:10:24 by taung             #+#    #+#             */
/*   Updated: 2025/05/06 15:46:49 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->setName("DiamondTrap_clap_name");
	this->_name = "a new DiamondTrap";
	this->setHP(FragTrap::getHP());
	this->setEP(ScavTrap::getEP());
	this->setDMG(FragTrap::getDMG());
}

DiamondTrap::DiamondTrap(std::string name) {
std::cout << "DiamondTrap name constructor called" << std::endl;
	this->setName(name + "_clap_name");
	this->_name = name;
	this->setHP(FragTrap::getHP());
	this->setEP(ScavTrap::getEP());
	this->setDMG(FragTrap::getDMG());
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
	if (this->getHP() < amount)
			this->setHP(0);
	else
		this->setHP(this->getHP() - amount);
}

void		DiamondTrap::beRepaired(unsigned int amount) {
if (this->getHP() > 0 && this->getEP() > 0) {
	std::cout << "DiamondTrap " << this->_name
	<< " repairs, gaining "
	<< amount << " points of hit points!"
	<<std::endl;
	this->setHP(this->getHP() + amount);
	this->setEP(this->getEP() - 1);
}
}

void	DiamondTrap::printStatus(void) const {
std::cout << "DiamondTrap : " << this->_name << std::endl
<< "HP       : " << this->getHP() << std::endl
<< "EP       : " << this->getEP() << std::endl
<< "DMG      : " << this->getDMG() << std::endl;
}
/*
This member function will display both its name and its ClapTrap name.
*/
void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap Name: " << this->getName() << std::endl;
	std::cout << "Its ClapTrap Name: " << this->_name << std::endl;
}
