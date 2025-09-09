/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:01:42 by taung             #+#    #+#             */
/*   Updated: 2025/09/04 20:56:41 by taung            ###   ########.fr       */
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
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/*
void identify(Base& p);
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.
*/
void	identify(Base& p) {

	try {
		const A tmp = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception& e) {}

	try {
		const B tmp = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception& e) {}

	try {
		const C tmp = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception& e) {}
}

int main() {

	Base *b = generate();
	identify(b);
	identify(*b);
}
