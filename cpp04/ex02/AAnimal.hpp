/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:29 by taung             #+#    #+#             */
/*   Updated: 2025/06/09 15:00:22 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class AAnimal {
	private:
		std::string whatAmI(void) const;

	protected:
		std::string type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		AAnimal&	operator=(const AAnimal& other);
		virtual ~AAnimal();
		virtual void	makeSound(void) const = 0;
		void	printAnimalDetails(void) const;
		std::string	getType(void) const;
		void		setType(std::string type);
};

#endif
