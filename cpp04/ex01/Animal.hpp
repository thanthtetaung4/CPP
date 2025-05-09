/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:29 by taung             #+#    #+#             */
/*   Updated: 2025/05/09 16:57:51 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>
#include <cstdlib>

class Animal {
	private:
		std::string whatAmI(void) const;

	protected:
		std::string type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		~Animal();
		void	printAnimalDetails(void) const;
};

#endif
