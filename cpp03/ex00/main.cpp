/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   main.cpp                                           :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
	/*   Updated: 2025/05/31 10:32:41 by taung            ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cassert>
#include <iostream>

void testClapTrap() {
	// Test default constructor
	std::cout << "\033[1;34mTesting default constructor...\033[0m" << std::endl;
	ClapTrap defaultClapTrap;
	assert(defaultClapTrap.getName() == "unkown clap trap");
	assert(defaultClapTrap.getHP() == 10);
	assert(defaultClapTrap.getEP() == 10);
	assert(defaultClapTrap.getDMG() == 0);
	std::cout << "\033[1;32mDefault constructor test passed! \033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test name constructor
	std::cout << "\033[1;34mTesting name constructor...\033[0m" << std::endl;
	ClapTrap namedClapTrap("test_clap");
	assert(namedClapTrap.getName() == "test_clap");
	assert(namedClapTrap.getHP() == 10);
	assert(namedClapTrap.getEP() == 10);
	assert(namedClapTrap.getDMG() == 0);
	std::cout << "\033[1;32mName constructor test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test attack
	std::cout << "\033[1;34mTesting attack...\033[0m" << std::endl;
	namedClapTrap.attack("target");
	assert(namedClapTrap.getEP() == 9); // Energy points decrease by 1
	std::cout << "\033[1;32mAttack test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test takeDamage
	std::cout << "Testing takeDamage...\033[0m" << std::endl;
	namedClapTrap.takeDamage(5);
	assert(namedClapTrap.getHP() == 5); // Hit points decrease by 5

	namedClapTrap.takeDamage(10);
	assert(namedClapTrap.getHP() == 0); // Hit points cannot go below 0
	std::cout << "\033[1;32mTakeDamage test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test beRepaired
	std::cout << "\033[1;34mTesting beRepaired...\033[0m" << std::endl;
	namedClapTrap.beRepaired(5);
	assert(namedClapTrap.getHP() == 0); // Unable to fix HP = 0
	assert(namedClapTrap.getEP() == 9); // Unable to fix so energy not decreased

	namedClapTrap.setHP(1);
	namedClapTrap.beRepaired(5);
	assert(namedClapTrap.getHP() == 6); // Hit points increase by 5
	assert(namedClapTrap.getEP() == 8); // Energy points decrease by 1
	std::cout << "\033[1;32mBeRepaired test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	// Test setters
	std::cout << "\033[1;34mTesting setters...\033[0m" << std::endl;
	namedClapTrap.setDMG(50);
	assert(namedClapTrap.getDMG() == 50);

	namedClapTrap.setName("new_name");
	assert(namedClapTrap.getName() == "new_name");

	namedClapTrap.setHP(20);
	assert(namedClapTrap.getHP() == 20);

	namedClapTrap.setEP(15);
	assert(namedClapTrap.getEP() == 15);
	std::cout << "\033[1;32mSetters test passed!\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	std::cout << "\033[1;32mAll tests passed!\033[0m" << std::endl;
}

int main() {
	testClapTrap();
	return 0;
}
