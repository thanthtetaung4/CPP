/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 11:25:15 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cassert>
#include <iostream>

void testScavTrap() {
	// Test default constructor
	std::cout << "\033[1;34mTesting default constructor...\033[0m" << std::endl;
	ScavTrap defaultScavTrap;
	assert(defaultScavTrap.getName() == "a new ScavTrap");
	assert(defaultScavTrap.getHP() == 100);
	assert(defaultScavTrap.getEP() == 50);
	assert(defaultScavTrap.getDMG() == 20);
	std::cout << "\033[1;32mDefault constructor test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test name constructor
	std::cout << "\033[1;34mTesting name constructor...\033[0m" << std::endl;
	ScavTrap namedScavTrap("test_scav");
	assert(namedScavTrap.getName() == "test_scav");
	assert(namedScavTrap.getHP() == 100);
	assert(namedScavTrap.getEP() == 50);
	assert(namedScavTrap.getDMG() == 20);
	std::cout << "\033[1;32mName constructor test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test attack
	std::cout << "\033[1;34mTesting attack...\033[0m" << std::endl;
	namedScavTrap.attack("target");
	assert(namedScavTrap.getEP() == 49); // Energy points decrease by 1
	std::cout << "\033[1;32mAttack test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test takeDamage
	std::cout << "\033[1;34mTesting takeDamage...\033[0m" << std::endl;
	namedScavTrap.takeDamage(50);
	assert(namedScavTrap.getHP() == 50); // Hit points decrease by 50

	namedScavTrap.takeDamage(60);
	assert(namedScavTrap.getHP() == 0); // Hit points cannot go below 0
	std::cout << "\033[1;32mTakeDamage test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test beRepaired
	std::cout << "\033[1;34mTesting beRepaired...\033[0m" << std::endl;
	namedScavTrap.beRepaired(30);
	assert(namedScavTrap.getHP() == 0); // Hit points increase by 30
	assert(namedScavTrap.getEP() == 49); // Energy points decrease by 1
	namedScavTrap.setHP(1);
	namedScavTrap.beRepaired(30);
	assert(namedScavTrap.getHP() == 31); // Hit points increase by 30
	assert(namedScavTrap.getEP() == 48); // Energy points decrease by 1
	std::cout << "\033[1;32mBeRepaired test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test guardGate
	std::cout << "\033[1;34mTesting guardGate...\033[0m" << std::endl;
	namedScavTrap.guardGate();
	std::cout << "\033[1;32mGuardGate test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	std::cout << "\033[1;32mAll tests passed!\033[0m" << std::endl;
}

int main() {
	testScavTrap();
	return 0;
}
