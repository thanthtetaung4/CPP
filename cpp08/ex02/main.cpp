/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:01:44 by taung             #+#    #+#             */
/*   Updated: 2025/09/22 18:08:25 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <iostream>
# include <vector>

int	main(void) {
	MutantStack<int>	mt;
	mt.push(0);
	mt.push(1);

	std::cout << mt << std::endl;

	MutantStack<char>	mt2;
	mt2.push('3');
	mt2.push('4');
	mt2.push('1');
	mt2.push('8');

	MutantStack<char>::iterator	iter2 = mt2.begin();

	iter2 += 2;

	std::cout << *(iter2) << std::endl;

	std::cout << mt2 << std::endl;
}
