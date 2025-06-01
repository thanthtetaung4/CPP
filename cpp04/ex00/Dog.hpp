/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:44 by taung             #+#    #+#             */
/*   Updated: 2025/06/01 12:11:27 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal {
	private:
		std::string	whatAmI(void) const;
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();
		void	makeSound(void) const;
};
