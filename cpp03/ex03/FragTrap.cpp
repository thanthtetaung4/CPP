/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:32:00 by taung             #+#    #+#             */
/*   Updated: 2025/05/07 14:33:49 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "a new FragTrap";
	this->_HP = 100;
	this->_EP = 100;
	this->_DMG = 30;
}

FragTrap::FragTrap(std::string name) {
std::cout << "FragTrap name constructor called" << std::endl;
this->_name = name;
	this->_HP = 100;
	this->_EP = 100;
	this->_DMG = 30;
}

FragTrap::FragTrap(const FragTrap& other) {
std::cout << "FragTrap copy constructor called" << std::endl;
if (this != &other) {
	*this = other;
}
}

FragTrap::~FragTrap(void) {
std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
std::cout << "FragTrap " << this->_name << " just high fived" << std::endl;
}

void		FragTrap::attack(const std::string& target) {
if (this->_HP > 0 && this->_EP > 0) {
	std::cout << "FragTrap " << this->_name
	<< " attacks " << target << ", causing "
	<< this->_DMG << " points of damage!"
	<<std::endl;
	this->_EP = this->_EP - 1;
}
}

void		FragTrap::takeDamage(unsigned int amount) {
std::cout << "FragTrap " << this->_name
	<< " takes " << amount << " points of damage!"
	<<std::endl;
	if (this->_HP < amount)
			this->_HP = 0;
	else
		this->_HP = this->_HP - amount;
}

void		FragTrap::beRepaired(unsigned int amount) {
if (this->_HP > 0 && this->_EP > 0) {
	std::cout << "FragTrap " << this->_name
	<< " repairs, gaining "
	<< amount << " points of hit points!"
	<<std::endl;
	this->_HP = this->_HP + amount;
	this->_EP = this->_EP - 1;
}
}

void	FragTrap::printStatus(void) const {
std::cout << "FragTrap : " << this->_name << std::endl
<< "HP       : " << this->_HP << std::endl
<< "EP       : " << this->_EP << std::endl
<< "DMG      : " << this->_DMG << std::endl;
}
