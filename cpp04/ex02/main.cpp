/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:47 by taung             #+#    #+#             */
/*   Updated: 2025/05/07 21:05:19 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	// Animal a;
	// Animal b("dog");
	// Animal c(b);

	// a = b;

	// a.printAnimalDetails();
	// b.printAnimalDetails();
	// c.printAnimalDetails();

	// Cat aCat;
	// Cat bCat("cat");
	// Cat cCat(bCat);

	// aCat = bCat;

	// aCat.printAnimalDetails();
	// bCat.printAnimalDetails();
	// cCat.printAnimalDetails();

	Dog a;
	Dog b("dog");
	Dog c(b);

	a = b;

	a.printAnimalDetails();
	b.printAnimalDetails();
	c.printAnimalDetails();

	std::string ideas[100];
}
