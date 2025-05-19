/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:25:21 by taung             #+#    #+#             */
/*   Updated: 2025/05/18 15:20:16 by taung            ###   ########.fr       */
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
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < trashCount; i++) {
		if (trash[i]) {
			delete trash[i];
			trash[i] = NULL;
		}
	}
	delete trash;
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

// Calculate and realloc the trash arrays to store trash inventory items
void	addToTrash(AMateria**& trash, int& count, AMateria* m) {
	AMateria** newTrash = new AMateria*[count + 1]();
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
		this->_inventory[idx] = m;
	}
}

void	Character::unequip(int idx) {
	if (0 <= idx <= 3) {

		this->_inventory[idx] = NULL;
	}
	else {
		std::cout << "Inventory slot unavailable!" << std::endl;
	}
}

void	Character::use(int, ICharacter&) {

}

std::string const & Character::getName() const {
	return (this->_name);
}
