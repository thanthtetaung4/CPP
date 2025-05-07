/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:43 by taung             #+#    #+#             */
/*   Updated: 2025/05/06 15:54:29 by taung            ###   ########.fr       */
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

ClapTrap&	ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other.getName();
		this->_HP = other.getHP();
		this->_EP = other.getEP();
		this->_DMG = other.getDMG();
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "claptrap " << this->_name << " is destroyed" << std::endl;
}

/*
	When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it regains <amount> hit points. Attacking and repairing
each cost 1 energy point. Of course, ClapTrap can’t do anything if it has no hit points or
energy points left. However, since these exercises serve as an introduction, the ClapTrap
instances should not interact directly with one another, and the parameters will not refer
to another instance of ClapTrap.
	In all of these member functions, you need to print a message to describe what hap-
pens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!
*/

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

void		ClapTrap::printStatus(void) const {
	std::cout << "ClapTrap : " << this->_name << std::endl
	<< "HP       : " << this->_HP << std::endl
	<< "EP       : " << this->_EP << std::endl
	<< "DMG      : " << this->_DMG << std::endl;
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

void		ClapTrap::setName(std::string name) {
	this->_name = name;
}
