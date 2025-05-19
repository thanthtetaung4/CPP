/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:07:48 by taung             #+#    #+#             */
/*   Updated: 2025/05/19 15:09:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __CHARATER_HPP__
# define __CHARATER_HPP__

# include "ICharacter.hpp"
# include "AMateria.hpp"

/*
The Character possesses an inventory of 4 slots, which means at most 4 Materias.
The inventory is empty upon construction. They equip the Materias in the first empty
slot they find, in the following order: from slot 0 to slot 3. If they try to add a Materia to
a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
are still forbidden). The unequip() member function must NOT delete the Materia!
Handle the Materias your character leaves on the floor as you like.
Save the addresses before calling unequip(), or anything else, but
don’t forget that you have to avoid memory leaks.
The use(int, ICharacter&) member function will have to use the Materia at the
slot[idx], and pass the target parameter to the AMateria::use function.

Your character’s inventory will be able to support any type of
AMateria.
Your Character must have a constructor taking its name as a parameter. Any copy
(using copy constructor or copy assignment operator) of a Character must be deep.
During copy, the Materias of a Character must be deleted before the new ones are added
to their inventory. Of course, the Materias must be deleted when a Character is destroyed.
*/

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*_inventory[4];
		AMateria	**trash;
		int			trashCount;
	protected:
		int	availableSot(void);
		void	addToTrash(AMateria**& trash, int& count, AMateria* m);
		bool	foundInTrash(int idx, AMateria* m);
	public:
		Character(void);
		Character(std::string name);
		Character(Character &other);
		Character&	operator=(const Character &other);
		~Character(void);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

# endif
