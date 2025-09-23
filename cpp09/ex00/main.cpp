/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:42 by taung             #+#    #+#             */
/*   Updated: 2025/09/23 22:00:32 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <map>

// int	main (int ac, char *av[]) {
// 	if (ac != 2)
// 		std::cerr << "error: invalid number of arguments" << std::endl;
// 	else {

// 	}
// }

int	main(void) {
	std::map<std::string, int>	m = {{"2009-01-02", 1}, {"2009-01-03", 2}, {"2009-01-04", 3}};

	m.insert({"2009-01-15", 4});

	for (auto it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << std::endl;
	}
	auto it = --(m.lower_bound("2009-01-05"));
	std::cout << it->first << std::endl;
	std::cout << (m.find("2009-01-12") == m.end()) << std::endl;
}
