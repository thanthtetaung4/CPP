/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:43 by taung             #+#    #+#             */
/*   Updated: 2025/05/09 15:41:39 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "unkown clap trap";
	this->_HP = 10;
	this->_EP = 10;
	this->_DMG = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap name constructor called" << std::endl;
	this->_name = name;
	this->_HP = 10;
	this->_EP = 10;
	this->_DMG = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	if (this != &other) {
		*this = other;
	}
}

/*
Here we can use other.protected-attribute because
C++ access control is class-based, not object-based.
*/
ClapTrap&	ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_DMG = other._DMG;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "claptrap " << this->_name << " is destroyed" << std::endl;
}

void		ClapTrap::attack(const std::string& target) {
	if (this->_HP > 0 && this->_EP > 0) {
		std::cout << "ClapTrap " << this->_name
		<< " attacks " << target << ", causing "
		<< this->_DMG << " points of damage!"
		<<std::endl;
		this->_EP--;
	}
}

void		ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name
		<< " takes " << amount << " points of damage!"
		<<std::endl;
		if (this->_HP < amount)
			this->_HP = 0;
		else
			this->_HP -= amount;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (this->_HP > 0 && this->_EP > 0) {
		std::cout << "ClapTrap " << this->_name
		<< " repairs, gaining "
		<< amount << " points of hit points!"
		<<std::endl;
		this->_HP += amount;
		this->_EP--;
	}
}

void		ClapTrap::printStatus(void) const {
	std::cout << "ClapTrap : " << this->_name << std::endl
	<< "HP       : " << this->_HP << std::endl
	<< "EP       : " << this->_EP << std::endl
	<< "DMG      : " << this->_DMG << std::endl;
}
