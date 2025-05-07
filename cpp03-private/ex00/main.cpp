/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
/*   Updated: 2025/04/28 15:00:24 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap c1("fireball");

	std::cout << c1.getName() << std::endl;
	c1.printStatus();
	c1.attack("enemy tower");
	c1.setDMG(100);
	c1.printStatus();
	c1.attack("enemy tower");
	c1.printStatus();
	c1.takeDamage(1000);
	c1.printStatus();
	c1.beRepaired(100);
	c1.printStatus();
}
