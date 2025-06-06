/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:47 by taung             #+#    #+#             */
/*   Updated: 2025/06/06 13:42:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test(void);

int main()
{
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << d->getType() << " " << std::endl;
	d->makeSound();
	std::cout << c->getType() << " " << std::endl;
	c->makeSound();
	meta->makeSound();

	WrongAnimal *wc = new WrongCat();
	wc->makeSound();

	delete meta;
	delete d;
	delete c;
	delete wc;

	test();

	return 0;
}

#include <cassert>
#include <iostream>

void test_animal_basics() {
	std::cout << "\033[1;34m[TEST] Animal basics...\033[0m" << std::endl;
	Animal a;
	assert(a.getType() == "animal");
	std::cout << "\033[1;32mPASS\033[0m: a.getType() == \"animal\" ✅" << std::endl;
	a.setType("beast");
	assert(a.getType() == "beast");
	std::cout << "\033[1;32mPASS\033[0m: a.getType() == \"beast\" ✅" << std::endl;

	Animal b("creature");
	assert(b.getType() == "creature");
	std::cout << "\033[1;32mPASS\033[0m: b.getType() == \"creature\" ✅" << std::endl;

	Animal c(b);
	assert(c.getType() == "creature");
	std::cout << "\033[1;32mPASS\033[0m: c.getType() == \"creature\" (copy) ✅" << std::endl;

	Animal d;
	d = b;
	assert(d.getType() == "creature");
	std::cout << "\033[1;32mPASS\033[0m: d.getType() == \"creature\" (assign) ✅" << std::endl;

	std::cout << "\033[1;32m[PASS] Animal basics\033[0m\n" << std::endl;
}

void test_dog_basics() {
	std::cout << "\033[1;34m[TEST] Dog basics...\033[0m" << std::endl;
	Dog d1;
	assert(d1.getType() == "Dog");
	std::cout << "\033[1;32mPASS\033[0m: d1.getType() == \"Dog\" ✅" << std::endl;

	Dog d2("Bulldog");
	assert(d2.getType() == "Bulldog");
	std::cout << "\033[1;32mPASS\033[0m: d2.getType() == \"Bulldog\" ✅" << std::endl;

	Dog d3(d2);
	assert(d3.getType() == "Bulldog");
	std::cout << "\033[1;32mPASS\033[0m: d3.getType() == \"Bulldog\" (copy) ✅" << std::endl;

	Dog d4;
	d4 = d2;
	assert(d4.getType() == "Bulldog");
	std::cout << "\033[1;32mPASS\033[0m: d4.getType() == \"Bulldog\" (assign) ✅" << std::endl;

	d1.makeSound(); // Should print "Meow" (intentional bug in Dog.cpp)
	std::cout << "\033[1;33mCHECK: Is it Dog sound❔\033[0m" << std::endl;

	std::cout << "\033[1;32m[PASS] Dog basics\033[0m\n" << std::endl;
}

void test_cat_basics() {
	std::cout << "\033[1;34m[TEST] Cat basics...\033[0m" << std::endl;
	Cat c1;
	assert(c1.getType() == "Cat");
	std::cout << "\033[1;32mPASS\033[0m: c1.getType() == \"Cat\" ✅" << std::endl;

	Cat c2("Siamese");
	assert(c2.getType() == "Siamese");
	std::cout << "\033[1;32mPASS\033[0m: c2.getType() == \"Siamese\" ✅" << std::endl;

	Cat c3(c2);
	assert(c3.getType() == "Siamese");
	std::cout << "\033[1;32mPASS\033[0m: c3.getType() == \"Siamese\" (copy) ✅" << std::endl;

	Cat c4;
	c4 = c2;
	assert(c4.getType() == "Siamese");
	std::cout << "\033[1;32mPASS\033[0m: c4.getType() == \"Siamese\" (assign) ✅" << std::endl;

	c1.makeSound(); // Should print "Meow"
	std::cout << "\033[1;33mCHECK: Is it Cat sound❔\033[0m" << std::endl;

	std::cout << "\033[1;32m[PASS] Cat basics\033[0m\n" << std::endl;
}

void test_polymorphism() {
	std::cout << "\033[1;34m[TEST] Polymorphism with Animal*...\033[0m" << std::endl;
	Animal* animals[2];
	animals[0] = new Dog();
	animals[1] = new Cat();

	assert(animals[0]->getType() == "Dog");
	std::cout << "\033[1;32mPASS\033[0m: animals[0]->getType() == \"Dog\" ✅" << std::endl;
	assert(animals[1]->getType() == "Cat");
	std::cout << "\033[1;32mPASS\033[0m: animals[1]->getType() == \"Cat\" ✅" << std::endl;

	animals[0]->makeSound(); // Should print "Woof"
	std::cout << "\033[1;33mCHECK: Is it Dog sound❔\033[0m" << std::endl;
	animals[1]->makeSound(); // Should print "Meow"
	std::cout << "\033[1;33mCHECK: Is it Cat sound❔\033[0m" << std::endl;

	delete animals[0];
	delete animals[1];
	std::cout << "\033[1;32m[PASS] Polymorphism with Animal*\033[0m\n" << std::endl;
}

void test(void) {
	std::cout << "\033[1;34m===== ex00 TESTS START =====\033[0m" << std::endl;
	test_animal_basics();
	test_dog_basics();
	test_cat_basics();
	test_polymorphism();
	std::cout << "\033[1;34m===== ex00 TESTS END =====\033[0m" << std::endl;
	std::cout << "\033[1;32mAll ex00 tests passed!\033[0m" << std::endl;
}
