/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 13:04:34 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
// #include "FragTrap.hpp"
// #include "ScavTrap.hpp"

// int main(void) {
// 	ScavTrap s1("tower");

// 	s1.printStatus();
// 	s1.attack("enemy tower");
// 	s1.printStatus();
// 	s1.attack("enemy tower");
// 	s1.printStatus();
// 	s1.takeDamage(1);
// 	s1.printStatus();
// 	s1.beRepaired(100);
// 	s1.printStatus();
// 	s1.guardGate();

// 	FragTrap f1("frag");

// 	f1.printStatus();
// 	f1.attack("enemy tower");
// 	f1.printStatus();
// 	f1.attack("enemy tower");
// 	f1.printStatus();
// 	f1.takeDamage(1);
// 	f1.printStatus();
// 	f1.takeDamage(1000);
// 	f1.printStatus();
// 	f1.beRepaired(100);
// 	f1.printStatus();
// 	f1.highFivesGuys();
// }

#include "FragTrap.hpp"
#include <cassert>
#include <iostream>

void testFragTrap() {
	// Test default constructor
	std::cout << "\033[1;34mTesting default constructor...\033[0m" << std::endl;
	FragTrap defaultFragTrap;
	assert(defaultFragTrap.getName() == "a new FragTrap");
	assert(defaultFragTrap.getHP() == 100);
	assert(defaultFragTrap.getEP() == 100);
	assert(defaultFragTrap.getDMG() == 30);
	std::cout << "\033[1;32mDefault constructor test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test name constructor
	std::cout << "\033[1;34mTesting name constructor...\033[0m" << std::endl;
	FragTrap namedFragTrap("test_frag");
	assert(namedFragTrap.getName() == "test_frag");
	assert(namedFragTrap.getHP() == 100);
	assert(namedFragTrap.getEP() == 100);
	assert(namedFragTrap.getDMG() == 30);
	std::cout << "\033[1;32mName constructor test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test attack
	std::cout << "\033[1;34mTesting attack...\033[0m" << std::endl;
	namedFragTrap.attack("target");
	assert(namedFragTrap.getEP() == 99); // Energy points decrease by 1
	std::cout << "\033[1;32mAttack test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test takeDamage
	std::cout << "\033[1;34mTesting takeDamage...\033[0m" << std::endl;
	namedFragTrap.takeDamage(50);
	assert(namedFragTrap.getHP() == 50); // Hit points decrease by 50

	namedFragTrap.takeDamage(60);
	assert(namedFragTrap.getHP() == 0); // Hit points cannot go below 0
	std::cout << "\033[1;32mTakeDamage test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test beRepaired
	std::cout << "\033[1;34mTesting beRepaired...\033[0m" << std::endl;
	namedFragTrap.beRepaired(30);
	assert(namedFragTrap.getHP() == 0); // Hit points increase by 30
	assert(namedFragTrap.getEP() == 99); // Energy points decrease by 1
	namedFragTrap.setHP(1);
	namedFragTrap.beRepaired(30);
	assert(namedFragTrap.getHP() == 31); // Hit points increase by 30
	assert(namedFragTrap.getEP() == 98); // Energy points decrease by 1
	std::cout << "\033[1;32mBeRepaired test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test highFivesGuys
	std::cout << "\033[1;34mTesting highFivesGuys...\033[0m" << std::endl;
	namedFragTrap.highFivesGuys();
	std::cout << "\033[1;32mHighFivesGuys test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	std::cout << "\033[1;32mAll tests passed!\033[0m" << std::endl;
}

int main() {
	testFragTrap();
	return 0;
}
