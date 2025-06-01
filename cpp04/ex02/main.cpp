/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:47 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 13:29:33 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int	main(void) {
// 	/*
// 	Animal	animals[10];

// 	for (int i = 0; i < 5; i++)
// 	{
// 		animals[i] = Dog("Dog");
// 		animals[i].makeSound();
// 	}
// 	for (int i = 5; i < 10; i++)
// 	{
// 		animals[i] = Cat("Cat");
// 		animals[i].makeSound();
// 	}
// 	*/
// 	// This causes the slicing problem
// 	// Cat & Dog are sliced into the Animal defeating the whole point of polymorphism.
// 	// This will seg fault because Brain is not copied and Dog tries to delete the non existance Brain. (Broken Polymorphism)

// 	AAnimal	*a[10];
// 	// AAnimal	b;

// 	for (int i = 0; i < 5; i++) {
// 		a[i] = new Dog("Dog"); // Upcasting: Dog* -> Animal*
// 		a[i]->makeSound();
// 	}
// 	for (int i = 5; i < 10; i++) {
// 		a[i] = new Cat("Cat"); // Upcasting: Cat* -> Animal*
// 		a[i]->makeSound();
// 	}
// 	for (int i = 0; i < 10; i++) {
// 		std::cout << i << std::endl;
// 		delete a[i];
// 	}
// }

/*
You can store a Dog* in an Animal* because Dog is-a Animal.

Upcasting (Dog* → Animal*) is safe and automatic.

This allows you to build polymorphic arrays like Animal* arr[10].

Virtual functions + base class pointers = runtime polymorphism.
*/

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <cassert>
#include <iostream>

void test_brain_deep_copy_dog() {
	std::cout << "\033[1;34m[TEST] Dog deep copy (Brain)...\033[0m" << std::endl;
	Dog d1("Dog");
	d1.ideate(0, "Chase the cat");
	d1.ideate(1, "Eat food");

	assert(d1.think(0) == "Chase the cat");
	std::cout << "\033[1;32mPASS\033[0m: d1.think(0) == \"Chase the cat\" ✅" << std::endl;
	assert(d1.think(1) == "Eat food");
	std::cout << "\033[1;32mPASS\033[0m: d1.think(1) == \"Eat food\" ✅" << std::endl;

	Dog d2 = d1; // Copy constructor
	assert(d1.getBrain() != d2.getBrain());
	std::cout << "\033[1;32mPASS\033[0m: d1.getBrain() != d2.getBrain() (deep copy) ✅" << std::endl;
	assert(d2.getType() == "Dog");
	std::cout << "\033[1;32mPASS\033[0m: d2.getType() == \"Dog\" ✅" << std::endl;
	assert(d2.think(0) == "Chase the cat");
	std::cout << "\033[1;32mPASS\033[0m: d2.think(0) == \"Chase the cat\" ✅" << std::endl;
	assert(d2.think(1) == "Eat food");
	std::cout << "\033[1;32mPASS\033[0m: d2.think(1) == \"Eat food\" ✅" << std::endl;

	assert(&d1 != &d2);
	std::cout << "\033[1;32mPASS\033[0m: &d1 != &d2 ✅" << std::endl;
	d2.ideate(0, "Sleep");
	assert(d1.think(0) == "Chase the cat");
	std::cout << "\033[1;32mPASS\033[0m: d1.think(0) still == \"Chase the cat\" after d2 modified ✅" << std::endl;
	assert(d2.think(0) == "Sleep");
	std::cout << "\033[1;32mPASS\033[0m: d2.think(0) == \"Sleep\" ✅" << std::endl;

	Dog d3("AnotherDog");
	d3 = d1; // Assignment operator
	assert(d1.getBrain() != d3.getBrain());
	std::cout << "\033[1;32mPASS\033[0m: d1.getBrain() != d3.getBrain() (deep copy assignment) ✅" << std::endl;
	assert(d3.getType() == "Dog");
	std::cout << "\033[1;32mPASS\033[0m: d3.getType() == \"Dog\" ✅" << std::endl;
	assert(d3.think(0) == "Chase the cat");
	std::cout << "\033[1;32mPASS\033[0m: d3.think(0) == \"Chase the cat\" ✅" << std::endl;
	d3.ideate(0, "Play fetch");
	assert(d1.think(0) == "Chase the cat");
	std::cout << "\033[1;32mPASS\033[0m: d1.think(0) still == \"Chase the cat\" after d3 modified ✅" << std::endl;
	assert(d3.think(0) == "Play fetch");
	std::cout << "\033[1;32mPASS\033[0m: d3.think(0) == \"Play fetch\" ✅" << std::endl;

	std::cout << "\033[1;32m[PASS] Dog deep copy (Brain)\033[0m\n" << std::endl;
}

void test_brain_deep_copy_cat() {
	std::cout << "\033[1;34m[TEST] Cat deep copy (Brain)...\033[0m" << std::endl;
	Cat c1("Cat");
	c1.ideate(0, "Catch mouse");
	c1.ideate(1, "Sleep on keyboard");

	assert(c1.think(0) == "Catch mouse");
	std::cout << "\033[1;32mPASS\033[0m: c1.think(0) == \"Catch mouse\" ✅" << std::endl;
	assert(c1.think(1) == "Sleep on keyboard");
	std::cout << "\033[1;32mPASS\033[0m: c1.think(1) == \"Sleep on keyboard\" ✅" << std::endl;

	Cat c2 = c1; // Copy constructor
	assert(c2.getType() == "Cat");
	std::cout << "\033[1;32mPASS\033[0m: c2.getType() == \"Cat\" ✅" << std::endl;
	assert(c1.getBrain() != c2.getBrain());
	std::cout << "\033[1;32mPASS\033[0m: c1.getBrain() != c2.getBrain() (deep copy) ✅" << std::endl;
	assert(c2.think(0) == "Catch mouse");
	std::cout << "\033[1;32mPASS\033[0m: c2.think(0) == \"Catch mouse\" ✅" << std::endl;
	assert(c2.think(1) == "Sleep on keyboard");
	std::cout << "\033[1;32mPASS\033[0m: c2.think(1) == \"Sleep on keyboard\" ✅" << std::endl;

	assert(&c1 != &c2);
	std::cout << "\033[1;32mPASS\033[0m: &c1 != &c2 ✅" << std::endl;
	c2.ideate(0, "Climb curtain");
	assert(c1.think(0) == "Catch mouse");
	std::cout << "\033[1;32mPASS\033[0m: c1.think(0) still == \"Catch mouse\" after c2 modified ✅" << std::endl;
	assert(c2.think(0) == "Climb curtain");
	std::cout << "\033[1;32mPASS\033[0m: c2.think(0) == \"Climb curtain\" ✅" << std::endl;

	Cat c3("AnotherCat");
	c3 = c1; // Assignment operator
	assert(c3.getType() == "Cat");
	std::cout << "\033[1;32mPASS\033[0m: c3.getType() == \"Cat\" ✅" << std::endl;
	assert(c1.getBrain() != c3.getBrain());
	std::cout << "\033[1;32mPASS\033[0m: c1.getBrain() != c3.getBrain() (deep copy assignment) ✅" << std::endl;
	assert(c3.think(0) == "Catch mouse");
	std::cout << "\033[1;32mPASS\033[0m: c3.think(0) == \"Catch mouse\" ✅" << std::endl;
	c3.ideate(0, "Play with yarn");
	assert(c1.think(0) == "Catch mouse");
	std::cout << "\033[1;32mPASS\033[0m: c1.think(0) still == \"Catch mouse\" after c3 modified ✅" << std::endl;
	assert(c3.think(0) == "Play with yarn");
	std::cout << "\033[1;32mPASS\033[0m: c3.think(0) == \"Play with yarn\" ✅" << std::endl;

	std::cout << "\033[1;32m[PASS] Cat deep copy (Brain)\033[0m\n" << std::endl;
}

void test_dog_cat_sound_and_type() {
	std::cout << "\033[1;34m[TEST] Dog/Cat sound and type...\033[0m" << std::endl;
	Dog d;
	assert(d.getType() == "Dog");
	std::cout << "\033[1;32mPASS\033[0m: d.getType() == \"Dog\" ✅" << std::endl;
	d.makeSound();

	Dog d2("Bulldog");
	assert(d2.getType() == "Bulldog");
	std::cout << "\033[1;32mPASS\033[0m: d2.getType() == \"Bulldog\" ✅" << std::endl;
	d2.makeSound();

	Cat c;
	assert(c.getType() == "Cat");
	std::cout << "\033[1;32mPASS\033[0m: c.getType() == \"Cat\" ✅" << std::endl;
	c.makeSound();

	Cat c2("Siamese");
	assert(c2.getType() == "Siamese");
	std::cout << "\033[1;32mPASS\033[0m: c2.getType() == \"Siamese\" ✅" << std::endl;
	c2.makeSound();
	std::cout << "\033[1;32m[PASS] Dog/Cat sound and type\033[0m\n" << std::endl;
}

void test_polymorphism() {
	std::cout << "\033[1;34m[TEST] Polymorphism with Animal*...\033[0m" << std::endl;
	AAnimal* animals[2];
	animals[0] = new Dog("Dog");
	animals[1] = new Cat("Cat");

	assert(animals[0]->getType() == "Dog");
	std::cout << "\033[1;32mPASS\033[0m: animals[0]->getType() == \"Dog\" ✅" << std::endl;
	assert(animals[1]->getType() == "Cat");
	std::cout << "\033[1;32mPASS\033[0m: animals[1]->getType() == \"Cat\" ✅" << std::endl;

	animals[0]->makeSound();
	animals[1]->makeSound();

	delete animals[0];
	delete animals[1];
	std::cout << "\033[1;32m[PASS] Polymorphism with Animal*\033[0m\n" << std::endl;
}

void test_brain_basics() {
	std::cout << "\033[1;34m[TEST] Brain basics...\033[0m" << std::endl;
	Brain b1;
	b1.setIdea("Eat", 0);
	b1.setIdea("Sleep", 1);

	assert(b1.getIdea(0) == "Eat");
	std::cout << "\033[1;32mPASS\033[0m: idea[0] == \"Eat\" ✅" << std::endl;

	assert(b1.getIdea(1) == "Sleep");
	std::cout << "\033[1;32mPASS\033[0m: idea[1] == \"Sleep\" ✅" << std::endl;

	// Test copy constructor
	Brain b2(b1);
	assert(b2.getIdea(0) == "Eat");
	std::cout << "\033[1;32mPASS\033[0m: copy constructor idea[0] == \"Eat\" ✅" << std::endl;

	assert(b2.getIdea(1) == "Sleep");
	std::cout << "\033[1;32mPASS\033[0m: copy constructor idea[1] == \"Sleep\" ✅" << std::endl;

	b2.setIdea("Play", 0);
	assert(b1.getIdea(0) == "Eat"); // Ensure deep copy
	std::cout << "\033[1;32mPASS\033[0m: deep copy, b1.idea[0] still == \"Eat\" after b2 modified ✅" << std::endl;

	// Test assignment operator
	Brain b3;
	b3 = b1;
	assert(b3.getIdea(0) == "Eat");
	std::cout << "\033[1;32mPASS\033[0m: assignment idea[0] == \"Eat\" ✅" << std::endl;

	b3.setIdea("Run", 1);
	assert(b1.getIdea(1) == "Sleep"); // Ensure deep copy
	std::cout << "\033[1;32mPASS\033[0m: deep copy, b1.idea[1] still == \"Sleep\" after b3 modified ✅" << std::endl;

	std::cout << "\033[1;32m[PASS] Brain basics\033[0m\n" << std::endl;
}

int main() {
	std::cout << "===== ex02 TESTS START =====" << std::endl;
	test_brain_basics();
	test_brain_deep_copy_dog();
	test_brain_deep_copy_cat();
	test_dog_cat_sound_and_type();
	test_polymorphism();
	std::cout << "===== ex02 TESTS END =====" << std::endl;
	std::cout << "All ex02 tests passed!" << std::endl;
	return 0;
}
