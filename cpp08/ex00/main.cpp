/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:10:50 by taung             #+#    #+#             */
/*   Updated: 2025/09/09 19:28:27 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "easyfind.hpp"
# include <unordered_set>
# include <iostream>
# include <vector>
# include <exception>

int	main(void) {
	std::unordered_set<int>	set1 = {1, 2, 3, 4, 5};
	std::vector<int>	set2 = {42, 41, 40, 39};
	std::unordered_set<long>	set3 = {1, 2, 3, 4, 5};
	// std::unordered_set<std::string>	set4 = {"1", "2", "3"};

	std::cout << easyfind(set1, 3) << std::endl;
	std::cout << easyfind(set2 , 9235) << std::endl;
	std::cout << easyfind(set3 , 9235) << std::endl;
	// std::cout << easyfind(set4 , 9235) << std::endl;
}
