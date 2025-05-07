/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:45 by taung             #+#    #+#             */
/*   Updated: 2025/05/07 14:34:41 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap s1("tower");

	s1.printStatus();
	s1.attack("enemy tower");
	s1.printStatus();
	s1.attack("enemy tower");
	s1.printStatus();
	s1.takeDamage(1);
	s1.printStatus();
	s1.beRepaired(100);
	s1.printStatus();
	s1.guardGate();
}
