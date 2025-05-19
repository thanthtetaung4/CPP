/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:25:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/19 21:23:28 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include "Cure.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"
# include "MateriaSource.hpp"

int	main(void) {
	// AMateria *materials[2];
	// materials[0] = new Ice("ice");
	// materials[1] = new Cure("cure");
	// std::cout << materials[0]->getType() << std::endl;
	// std::cout << materials[1]->getType() << std::endl;
	// Character	*c = new Character("tayza");
	// c->equip(materials[0]);
	// c->equip(materials[1]);
	// c->use(0, *c);
	// c->use(1, *c);
	// c->unequip(0);
	// c->use(0, *c);
	// c->equip(materials[0]);
	// c->use(0, *c);
	// delete c;


	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

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

	return 0;
}
