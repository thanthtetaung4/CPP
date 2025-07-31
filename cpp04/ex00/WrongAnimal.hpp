/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:40:02 by taung             #+#    #+#             */
/*   Updated: 2025/05/27 20:56:23 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __WRONG_ANIMAL_HPP__
# define __WRONG_ANIMAL_HPP__

# include <iostream>

class WrongAnimal {
	private:
		std::string whatAmI(void) const;

	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		~WrongAnimal();
		void	makeSound(void) const;
		void	printAnimalDetails(void) const;
		std::string	getType(void) const;
		void		setType(std::string type);
};

# endif
