/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 13:48:29 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <cassert>
#include <iostream>

void testDiamondTrap() {
	// Test default constructor
	std::cout << "\033[1;34mTesting default constructor...\033[0m" << std::endl;
	DiamondTrap defaultDiamondTrap;
	// defaultDiamondTrap.printStatus();
	assert(defaultDiamondTrap.getName() == "a new DiamondTrap");
	assert(defaultDiamondTrap.getHP() == 100); // Inherits FragTrap's HP
	assert(defaultDiamondTrap.getEP() == 50);  // Inherits ScavTrap's EP
	assert(defaultDiamondTrap.getDMG() == 30); // Inherits FragTrap's DMG
	std::cout << "\033[1;32mDefault constructor test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test name constructor
	std::cout << "\033[1;34mTesting name constructor...\033[0m" << std::endl;
	DiamondTrap namedDiamondTrap("test_diamond");
	assert(namedDiamondTrap.getName() == "test_diamond_clap_name");
	assert(namedDiamondTrap.getDiamondTrapName() == "test_diamond");
	assert(namedDiamondTrap.getHP() == 100);
	assert(namedDiamondTrap.getEP() == 50);
	assert(namedDiamondTrap.getDMG() == 30);
	std::cout << "\033[1;32mName constructor test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test attack
	std::cout << "\033[1;34mTesting attack...\033[0m" << std::endl;
	namedDiamondTrap.attack("target");
	assert(namedDiamondTrap.getEP() == 49); // Energy points decrease by 1
	std::cout << "\033[1;32mAttack test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test takeDamage
	std::cout << "\033[1;34mTesting takeDamage...\033[0m" << std::endl;
	namedDiamondTrap.takeDamage(50);
	assert(namedDiamondTrap.getHP() == 50); // Hit points decrease by 50

	namedDiamondTrap.takeDamage(60);
	assert(namedDiamondTrap.getHP() == 0); // Hit points cannot go below 0
	std::cout << "\033[1;32mTakeDamage test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test beRepaired
	std::cout << "\033[1;34mTesting beRepaired...\033[0m" << std::endl;
	namedDiamondTrap.beRepaired(30);
	assert(namedDiamondTrap.getHP() == 0); // Hit points increase by 30
	assert(namedDiamondTrap.getEP() == 49); // Energy points decrease by 1
	namedDiamondTrap.setHP(1);
	namedDiamondTrap.beRepaired(30);
	assert(namedDiamondTrap.getHP() == 31); // Hit points increase by 30
	assert(namedDiamondTrap.getEP() == 48); // Energy points decrease by 1
	std::cout << "\033[1;32mBeRepaired test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test highFivesGuys
	std::cout << "\033[1;34mTesting highFivesGuys...\033[0m" << std::endl;
	namedDiamondTrap.highFivesGuys();
	std::cout << "\033[1;33mHighFivesGuys test passed?\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test guardGate
	std::cout << "\033[1;34mTesting guardGate...\033[0m" << std::endl;
	namedDiamondTrap.guardGate();
	std::cout << "\033[1;33mGuardGate test passed?\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test whoAmI
	std::cout << "\033[1;34mTesting whoAmI...\033[0m" << std::endl;
	namedDiamondTrap.whoAmI();
	std::cout << "\033[1;33mWhoAmI test passed?\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	std::cout << "\033[1;32mAll tests passed!\033[0m" << std::endl;
}

int main() {
	testDiamondTrap();
	return 0;
}
