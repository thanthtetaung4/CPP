/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:47 by taung             #+#    #+#             */
/*   Updated: 2025/05/12 20:56:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int	main(void) {
// 	// Animal a;
// 	// Animal b("dog");
// 	// Animal c(b);

// 	// a = b;

// 	// a.printAnimalDetails();
// 	// b.printAnimalDetails();
// 	// c.printAnimalDetails();

// 	// Cat aCat;
// 	// Cat bCat("cat");
// 	// Cat cCat(bCat);

// 	// aCat = bCat;

// 	// aCat.printAnimalDetails();
// 	// bCat.printAnimalDetails();
// 	// cCat.printAnimalDetails();

// 	Dog a;
// 	Dog b("dog");
// 	Dog c(b);

// 	a = b;

// 	a.printAnimalDetails();
// 	b.printAnimalDetails();
// 	c.printAnimalDetails();
// }


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	return 0;
}
