/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:55:16 by taung             #+#    #+#             */
/*   Updated: 2025/03/20 18:04:07 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main(void) {
	Zombie*	z = newZombie("bob");
	z->announce();
  std::cout << "Hello Zombies" << std::endl;
	randomChump("alex");
	delete(z);
	return (0);
}
