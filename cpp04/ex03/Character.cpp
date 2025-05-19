/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:25:21 by taung             #+#    #+#             */
/*   Updated: 2025/05/19 20:40:37 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(void) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	this->trashCount = 0;
	this->trash = NULL;
	std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string name) {
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	this->trashCount = 0;
	this->trash = NULL;
	std::cout << "parameterised Character constructor called" << std::endl;
}

Character::Character(Character &other) {
	if (this != &other) {
		*this = other;
	}
	std::cout << "Copy Character constructor called" << std::endl;
}

Character&	Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			this->_inventory[i] = other._inventory[i];
		}
	}
	std::cout << "Copy assignment character operator called" << std::endl;
	return (*this);
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (foundInTrash(0, _inventory[i]))
			continue;
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < trashCount; i++) {
		if (trash[i]) {
			delete trash[i];
			trash[i] = NULL;
		}
	}
	delete []trash;
	trash = NULL;
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

//Find the unequipped item in the trash from idx
bool	Character::foundInTrash(int idx, AMateria *m) {
	while (idx < this->trashCount) {
		if (trash[idx] == m)
			return (true);
		idx++;
	}
	return (false);
}

// Calculate and realloc the trash arrays to store trash inventory items
void	Character::addToTrash(AMateria**& trash, int& count, AMateria* m) {
	AMateria** newTrash = new AMateria*[count + 1]();
	if (foundInTrash(0, m))
		return;
	for (int i = 0; i < count; ++i)
		newTrash[i] = trash[i];
	newTrash[count] = m;
	delete[] trash;
	trash = newTrash;
	count++;
}

void	Character::equip(AMateria* m) {
	int	idx;

	idx = this->availableSot();
	if (idx == -1) {
		std::cout << "Inventory is full" << std::endl;
	}
	else {
		if (!m)
			return;
		this->_inventory[idx] = m;
		std::cout << this->_name << " equipped " << this->_inventory[idx]->getType() << std::endl;
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
		if (!foundInTrash(0, this->_inventory[idx]))
		{
			addToTrash(this->trash, this->trashCount, this->_inventory[idx]);
			std::cout << this->_inventory[idx]->getType() << " unequipped from " << this->_name << std::endl;
			this->_inventory[idx] = NULL;
		}
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
