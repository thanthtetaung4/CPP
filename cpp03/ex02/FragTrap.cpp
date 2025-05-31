/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:32:00 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 14:22:00 by taung            ###   ########.fr       */
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

const std::string	FragTrap::myName(void) const {
	return	("Frag Trap");
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
