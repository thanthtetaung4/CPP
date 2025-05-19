/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:25:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/18 14:53:04 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include "Cure.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"

int	main(void) {
	Ice ice("ice");
	Cure cure("cure");
	std::cout << ice.getType() << std::endl;
	std::cout << cure.getType() << std::endl;

	Character	*c = new Character();
	delete c;
}
