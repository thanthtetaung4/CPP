/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:01:42 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 12:42:29 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <exception>

int getRandom123() {
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(0));
		seeded = true;
	}
	return std::rand() % 3 + 1;
}

/*
Base * generate(void);
It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
*/
Base*	generate(void) {
	switch (getRandom123())
	{
	case 1:
		std::cout << "Class A is generated" << std::endl;
		return (dynamic_cast<Base*>(new A()));
	case 2:
		std::cout << "Class B is generated" << std::endl;
		return (dynamic_cast<Base*>(new B()));
	case 3:
		std::cout << "Class C is generated" << std::endl;
		return (dynamic_cast<Base*>(new C()));
	}
	return NULL;
}

/*
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B", or "C".
*/
void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/*
void identify(Base& p);
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.
*/
void	identify(Base& p) {
	int	identifier = 3;

	try {
		dynamic_cast<A&>(p);
	} catch (const std::exception& e) {
		identifier--;
	}

	if (identifier == 3) {
		std::cout << "A" << std::endl;
		return;
	}

	try {
		dynamic_cast<B&>(p);
	} catch (const std::exception& e) {
		identifier--;
	}

	if (identifier == 2) {
		std::cout << "B" << std::endl;
		return;
	}

	try {
		dynamic_cast<C&>(p);
	} catch (const std::exception& e) {
		identifier--;
	}

	if (identifier == 1) {
		std::cout << "C" << std::endl;
		return;
	}
	else
		std::cerr << "err: not a valid derived class" << std::endl;
}

int main() {

	Base *b = generate();
	identify(b);
	identify(*b);
}
