/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:53:07 by taung             #+#    #+#             */
/*   Updated: 2025/05/19 19:53:59 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *materias[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource& other);
		MateriaSource& operator=(MateriaSource& other);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
