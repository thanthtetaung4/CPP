/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:25:21 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 19:57:14 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(void) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string name) {
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "parameterised Character constructor called" << std::endl;
}

Character::Character(Character &other) {
	this->_name = other._name;

	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}

	std::cout << "Copy Character constructor called" << std::endl;
}

Character& Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other._name;

		// Clean existing inventory
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i]) {
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}

		// Deep copy other inventory
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i]) {
				this->_inventory[i] = other._inventory[i]->clone();
				this->_inventory[i]->setOwnership(this);
			}
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout << "Copy assignment character operator called" << std::endl;
	return (*this);
}

Character::~Character(void) {
	// Clean Inventory
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character destroyed" << std::endl;
}

// Find the next available in the inventory
int	Character::availableSot(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL)
			return (i);
	}
	return (-1);
}

void	Character::equip(AMateria* m) {
	int	idx;

	idx = this->availableSot();
	if (idx == -1) {
		std::cout << "Inventory is full" << std::endl;
	}
	else {
		if (!m) {
			std::cout << "Materia is NULL" << std::endl;
			return;
		}
		if (m->getOwnership() != NULL) {
			m->getOwnership() == this ? std::cout << m->getType() << " is already equipped" : std::cout << m->getType() + " is already equipped by other character";
			std::cout << std::endl;
			return;
		}
		this->_inventory[idx] = m;
		this->_inventory[idx]->setOwnership(this);
		std::cout << this->_name << " equipped " << this->_inventory[idx]->getType() << std::endl;
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
			std::cout << this->_inventory[idx]->getType() << " unequipped from " << this->_name << std::endl;
			this->_inventory[idx]->setOwnership(NULL);
			this->_inventory[idx] = NULL;
	}
	else {
		std::cout << "Inventory slot unavailable!" << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (this->_inventory[idx] != NULL) {
		std::cout << this->_name << " ";
		this->_inventory[idx]->use(target);
	}
	else
		std::cout << "nothing is equipped at this inventory slot" << std::endl;
}

std::string const & Character::getName() const {
	return (this->_name);
}
