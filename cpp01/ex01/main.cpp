/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:55:16 by taung             #+#    #+#             */
/*   Updated: 2025/03/20 20:09:39 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main(void) {
	Zombie*	zhorde = zombieHorde(5, "bob");
	zhorde[0].announce();
	zhorde[1].announce();
	zhorde[2].announce();
	zhorde[3].announce();
	zhorde[4].announce();
	return (0);
}
