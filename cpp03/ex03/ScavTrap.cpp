/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:04:23 by taung             #+#    #+#             */
/*   Updated: 2025/05/09 15:42:15 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
		std::cout << "ScavTrap default constructor called" << std::endl;
		this->_name = "a new ScavTrap";
		this->_HP = 100;
		this->_EP = 50;
		this->_DMG = 20;
		this->defaultEP = 50;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_name = name;
		this->_HP = 100;
		this->_EP = 50;
		this->_DMG = 20;
		this->defaultEP = 50;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	if (this != &other) {
		*this = other;
	}
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is in guard mode" << std::endl;
}

void		ScavTrap::attack(const std::string& target) {
	if (this->_HP > 0 && this->_EP > 0) {
		std::cout << "ScavTrap " << this->_name
		<< " attacks " << target << ", causing "
		<< this->_DMG << " points of damage!"
		<<std::endl;
		this->_EP = this->_EP - 1;
	}
}

void		ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "ScavTrap " << this->_name
		<< " takes" << amount << " points of damage!"
		<<std::endl;
		if (this->_HP < amount)
			this->_HP = 0;
		else
			this->_HP = this->_HP - amount;
}

void		ScavTrap::beRepaired(unsigned int amount) {
	if (this->_HP > 0 && this->_EP > 0) {
		std::cout << "ScavTrap " << this->_name
		<< " repairs, gaining "
		<< amount << " points of hit points!"
		<<std::endl;
		this->_HP = this->_HP + amount;
		this->_EP = this->_EP - 1;
	}
}

void	ScavTrap::printStatus(void) const {
	std::cout << "ScavTrap : " << this->_name << std::endl
	<< "HP       : " << this->_HP << std::endl
	<< "EP       : " << this->_EP << std::endl
	<< "DMG      : " << this->_DMG << std::endl;
}

unsigned int	ScavTrap::getDefaultEP(void) const {
	return (this->defaultEP);
}
