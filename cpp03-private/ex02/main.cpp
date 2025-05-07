/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
/*   Updated: 2025/05/06 13:58:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.h"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap s1("tower");

	std::cout << s1.getName() << std::endl;
	s1.printStatus();
	s1.attack("enemy tower");
	s1.setDMG(100);
	s1.printStatus();
	s1.attack("enemy tower");
	s1.printStatus();
	s1.takeDamage(1);
	s1.printStatus();
	s1.beRepaired(100);
	s1.printStatus();
	s1.guardGate();

	FragTrap f1("frag");

	std::cout << f1.getName() << std::endl;
	f1.printStatus();
	f1.attack("enemy tower");
	f1.setDMG(100);
	f1.printStatus();
	f1.attack("enemy tower");
	f1.printStatus();
	f1.takeDamage(1);
	f1.printStatus();
	f1.takeDamage(1000);
	f1.printStatus();
	f1.beRepaired(100);
	f1.printStatus();
	f1.highFivesGuys();
}
