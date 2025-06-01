/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:44 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 13:00:55 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		std::string	whatAmI(void) const;
		Brain	*brain;
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();
		void	makeSound(void) const;
		std::string	think(int index) const;
		void	ideate(int index, std::string idea);
		const Brain*	getBrain() const;
};

# endif
