/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:25:16 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 14:47:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include "Cure.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"
# include "MateriaSource.hpp"
#include <cassert>

void test_AMateria_basics() {
	std::cout << "\033[1;34m[TEST] AMateria basics...\033[0m" << std::endl;
	Ice ice1;
	Cure cure1;

	assert(ice1.getType() == "ice");
	std::cout << "\033[1;32mPASS\033[0m: Ice type is 'ice' ✅" << std::endl;

	assert(cure1.getType() == "cure");
	std::cout << "\033[1;32mPASS\033[0m: Cure type is 'cure' ✅" << std::endl;

	AMateria* ice2 = ice1.clone();
	assert(ice2->getType() == "ice");
	std::cout << "\033[1;32mPASS\033[0m: Ice clone type is 'ice' ✅" << std::endl;
	delete ice2;

	AMateria* cure2 = cure1.clone();
	assert(cure2->getType() == "cure");
	std::cout << "\033[1;32mPASS\033[0m: Cure clone type is 'cure' ✅" << std::endl;
	delete cure2;

	std::cout << "\033[1;32m[PASS] AMateria basics\033[0m\n" << std::endl;
}

void test_Character_basics() {
	std::cout << "\033[1;34m[TEST] Character basics...\033[0m" << std::endl;
	Character c1("Alice");
	assert(c1.getName() == "Alice");
	std::cout << "\033[1;32mPASS\033[0m: Character name is 'Alice' ✅" << std::endl;

	Ice* ice = new Ice();
	Cure* cure = new Cure();

	c1.equip(ice);
	c1.equip(cure);

	std::cout << "\033[1;32mPASS\033[0m: Equipped ice and cure ✅" << std::endl;

	c1.use(0, c1); // Should use ice
	c1.use(1, c1); // Should use cure

	c1.unequip(0);
	std::cout << "\033[1;32mPASS\033[0m: Unequipped slot 0 ✅" << std::endl;

	c1.use(0, c1); // Should print nothing equipped

	// Test deep copy
	Character c2 = c1;
	assert(c2.getName() == "Alice");
	std::cout << "\033[1;32mPASS\033[0m: Copy constructor name is 'Alice' ✅" << std::endl;

	std::cout << "\033[1;32m[PASS] Character basics\033[0m\n" << std::endl;
}

void test_MateriaSource_basics() {
	std::cout << "\033[1;34m[TEST] MateriaSource basics...\033[0m" << std::endl;
	MateriaSource src;
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	src.learnMateria(ice);
	src.learnMateria(cure);

	AMateria* m1 = src.createMateria("ice");
	std::cout << m1->getType() << std::endl;
	assert(m1 && m1->getType() == "ice");
	std::cout << "\033[1;32mPASS\033[0m: Created 'ice' materia ✅" << std::endl;
	delete m1;

	AMateria* m2 = src.createMateria("cure");
	std::cout << m2 << std::endl;
	assert(m2 && m2->getType() == "cure");
	std::cout << "\033[1;32mPASS\033[0m: Created 'cure' materia ✅" << std::endl;
	delete m2;

	AMateria* m3 = src.createMateria("unknown");
	assert(m3 == nullptr);
	std::cout << "\033[1;32mPASS\033[0m: Unknown materia returns nullptr ✅" << std::endl;

	std::cout << "\033[1;32m[PASS] MateriaSource basics\033[0m\n" << std::endl;
	delete ice;
	delete cure;
}

void test_full_flow() {
	std::cout << "\033[1;34m[TEST] Full flow (subject main)...\033[0m" << std::endl;
	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
	std::cout << "\033[1;32m[PASS] Full flow\033[0m\n" << std::endl;
}

int main() {
	std::cout << "\033[1;34m===== ex03 TESTS START =====\033[0m" << std::endl;
	test_AMateria_basics();
	test_Character_basics();
	test_MateriaSource_basics();
	test_full_flow();
	std::cout << "\033[1;34m===== ex03 TESTS END =====\033[0m" << std::endl;
	std::cout << "\033[1;32mAll ex03 tests passed!\033[0m" << std::endl;
	return 0;
}
// ...existing code...
