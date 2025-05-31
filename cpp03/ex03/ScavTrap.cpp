/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:04:23 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 14:29:02 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
		std::cout << "ScavTrap default constructor called" << std::endl;
		this->_name = "a new ScavTrap";
		this->_HP = 100;
		this->_EP = 50;
		this->_DMG = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_name = name;
		this->_HP = 100;
		this->_EP = 50;
		this->_DMG = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	if (this != &other) {
		*this = other;
	}
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		this->_DMG = other._DMG;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_name = other._name;
	}
	return *this;
}

void		ScavTrap::attack(const std::string& target) {
	if (this->_HP > 0 && this->_EP > 0) {
		std::cout << "ScavTrap " << this->_name
		<< " attacks " << target << ", causing "
		<< this->_DMG << " points of damage!"
		<<std::endl;
		this->_EP--;
	}
}

const std::string	ScavTrap::myName(void) const{
	return	("Scav Trap");
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is in guard mode" << std::endl;
}

unsigned int	ScavTrap::getDefaultEP(void) const {
	return	(this->defaultEP);
}
