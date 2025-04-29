/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:04:23 by taung             #+#    #+#             */
/*   Updated: 2025/04/29 16:50:47 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
		std::cout << "ScavTrap default constructor called" << std::endl;
		this->setName("a new ScavTrap");
		this->setHP(100);
		this->setEP(50);
		this->setDMG(20);
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->setName(name);
		this->setHP(100);
		this->setEP(50);
		this->setDMG(20);
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	if (this != &other) {
		*this = other;
	}
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->getName() << " is in guard mode" << std::endl;
}

void		ScavTrap::attack(const std::string& target) {
	if (this->getHP() > 0 && this->getEP() > 0) {
		std::cout << "ScavTrap " << this->getName()
		<< " attacks " << target << ", causing "
		<< this->getDMG() << " points of damage!"
		<<std::endl;
		this->setEP(this->getEP() - 1);
	}
}

void		ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "ScavTrap " << this->getName()
		<< " takes" << amount << " points of damage!"
		<<std::endl;
		this->setHP(this->getHP() - amount);
}

void		ScavTrap::beRepaired(unsigned int amount) {
	if (this->getHP() > 0 && this->getEP() > 0) {
		std::cout << "ScavTrap " << this->getName()
		<< " repairs, gaining "
		<< amount << " points of hit points!"
		<<std::endl;
		this->setHP(this->getHP() + amount);
		this->setEP(this->getEP() - 1);
	}
}

void	ScavTrap::printStatus(void) const {
	std::cout << "ScavTrap : " << this->getName() << std::endl
	<< "HP       : " << this->getHP() << std::endl
	<< "EP       : " << this->getEP() << std::endl
	<< "DMG      : " << this->getDMG() << std::endl;
}
