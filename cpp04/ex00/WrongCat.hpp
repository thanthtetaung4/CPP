/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:40:02 by taung             #+#    #+#             */
/*   Updated: 2025/06/06 13:34:51 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __WRONG_CAT_HPP__
# define __WRONG_CAT_HPP__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:
		std::string	whatAmI(void) const;
	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat& other);
		WrongCat&	operator=(const WrongCat& other);
		~WrongCat();
		void	makeSound(void) const;
};

# endif
