/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:47 by taung             #+#    #+#             */
/*   Updated: 2025/05/12 21:45:22 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	/*
	Animal	animals[10];

	for (int i = 0; i < 5; i++)
	{
		animals[i] = Dog("Dog");
		animals[i].makeSound();
	}
	for (int i = 5; i < 10; i++)
	{
		animals[i] = Cat("Cat");
		animals[i].makeSound();
	}
	*/
	// This causes the slicing problem
	// Cat & Dog are sliced into the Animal defeating the whole point of polymorphism.
	// This will seg fault because Brain is not copied and Dog tries to delete the non existance Brain. (Broken Polymorphism)

	Animal	*a[10];

	for (int i = 0; i < 5; i++) {
		a[i] = new Dog("Dog"); // Upcasting: Dog* -> Animal*
		a[i]->makeSound();
	}
	for (int i = 5; i < 10; i++) {
		a[i] = new Cat("Cat"); // Upcasting: Cat* -> Animal*
		a[i]->makeSound();
	}
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		delete a[i];
	}
}

/*
You can store a Dog* in an Animal* because Dog is-a Animal.

Upcasting (Dog* → Animal*) is safe and automatic.

This allows you to build polymorphic arrays like Animal* arr[10].

Virtual functions + base class pointers = runtime polymorphism.
*/
