/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:43 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 12:18:29 by taung            ###   ########.fr       */
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

const std::string	ClapTrap::myName(void) const {
	return ("Clap Trap");
}

void		ClapTrap::attack(const std::string& target) {
	if (this->_HP > 0 && this->_EP > 0) {
		std::cout << this->myName() << " " << this->_name
		<< " attacks " << target << ", causing "
		<< this->_DMG << " points of damage!"
		<<std::endl;
		this->_EP--;
	}
}

void		ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->myName() << " " << this->_name
		<< " takes " << amount << " points of damage!"
		<<std::endl;
		if (this->_HP < amount)
			this->_HP = 0;
		else
			this->_HP -= amount;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (this->_HP > 0 && this->_EP > 0) {
		std::cout << this->myName() << " " << this->_name
		<< " repairs, gaining "
		<< amount << " points of hit points!"
		<<std::endl;
		this->_HP += amount;
		this->_EP--;
	}
	else
		std::cout << "\033[1;31mUnable to repair a dead " << this->myName() << " 😵 \033[0m" << std::endl;
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int			ClapTrap::getHP(void) const {
	return (this->_HP);
}

unsigned int			ClapTrap::getEP(void) const {
	return (this->_EP);
}

int			ClapTrap::getDMG(void) const {
	return (this->_DMG);
}

void		ClapTrap::setName(std::string name) {
	this->_name = name;
}

void		ClapTrap::setHP(unsigned int amount) {
	this->_HP = amount;
}

void		ClapTrap::setEP(int amount) {
	this->_EP = amount;
}

void		ClapTrap::setDMG(int amount) {
	this->_DMG = amount;
}

void		ClapTrap::printStatus(void) const {
	std::cout << this->myName() << " : " << this->_name << std::endl
	<< "HP       : " << this->_HP << std::endl
	<< "EP       : " << this->_EP << std::endl
	<< "DMG      : " << this->_DMG << std::endl;
}
