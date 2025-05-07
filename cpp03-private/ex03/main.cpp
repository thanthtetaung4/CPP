/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
/*   Updated: 2025/05/06 15:45:31 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap d1("dia");

	std::cout << d1.getName() << std::endl;
	d1.printStatus();
	d1.attack("enemy tower");
	d1.setDMG(100);
	d1.printStatus();
	d1.attack("enemy tower");
	d1.printStatus();
	d1.takeDamage(1);
	d1.printStatus();
	d1.takeDamage(1000);
	d1.printStatus();
	d1.beRepaired(100);
	d1.printStatus();
	d1.highFivesGuys();
	d1.whoAmI();
}
