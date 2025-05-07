/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:32:00 by taung             #+#    #+#             */
/*   Updated: 2025/05/06 15:55:31 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Name, which is passed as a parameter to the constructor
• Hit points (100), representing the health of the ClapTrap
• Energy points (100)
• Attack damage (30)
FragTrap has a special ability too:
void highFivesGuys(void);
*/

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setName("a new FragTrap");
	this->setHP(100);
	this->setEP(100);
	this->setDMG(30);
}

FragTrap::FragTrap(std::string name) {
std::cout << "FragTrap name constructor called" << std::endl;
this->setName(name);
	this->setHP(100);
	this->setEP(100);
	this->setDMG(30);
}

FragTrap::FragTrap(const FragTrap& other) {
std::cout << "FragTrap copy constructor called" << std::endl;
if (this != &other) {
	*this = other;
}
}

FragTrap::~FragTrap(void) {
std::cout << "FragTrap " << this->getName() << " is destroyed" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
std::cout << "FragTrap " << this->getName() << " just high fived" << std::endl;
}

void		FragTrap::attack(const std::string& target) {
if (this->getHP() > 0 && this->getEP() > 0) {
	std::cout << "FragTrap " << this->getName()
	<< " attacks " << target << ", causing "
	<< this->getDMG() << " points of damage!"
	<<std::endl;
	this->setEP(this->getEP() - 1);
}
}

void		FragTrap::takeDamage(unsigned int amount) {
std::cout << "FragTrap " << this->getName()
	<< " takes " << amount << " points of damage!"
	<<std::endl;
	if (this->getHP() < amount)
			this->setHP(0);
	else
		this->setHP(this->getHP() - amount);
}

void		FragTrap::beRepaired(unsigned int amount) {
if (this->getHP() > 0 && this->getEP() > 0) {
	std::cout << "FragTrap " << this->getName()
	<< " repairs, gaining "
	<< amount << " points of hit points!"
	<<std::endl;
	this->setHP(this->getHP() + amount);
	this->setEP(this->getEP() - 1);
}
}

void	FragTrap::printStatus(void) const {
std::cout << "FragTrap : " << this->getName() << std::endl
<< "HP       : " << this->getHP() << std::endl
<< "EP       : " << this->getEP() << std::endl
<< "DMG      : " << this->getDMG() << std::endl;
}
