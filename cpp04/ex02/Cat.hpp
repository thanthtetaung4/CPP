/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:39 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 13:14:18 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __CAT_HPP__
# define __CAT_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		std::string	whatAmI(void) const;
		Brain	*brain;
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();
		void	makeSound(void) const;
		std::string	think(int index) const;
		void	ideate(int index, std::string idea);
		const Brain*	getBrain() const;
};

# endif
