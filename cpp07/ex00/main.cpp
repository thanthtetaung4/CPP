/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:37:31 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 17:06:00 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"
# include <iostream>

int main() {
	int	i = 10;
	int	j = 20;

	std::cout << (&i == &min(i,j)) << (&j == &max(i,j)) << std::endl;

	std::cout << i << " , " << j << std::endl;
	swap(i,j);
	std::cout << i << " , " << j << std::endl;

	std::cout << min(i, j) << std::endl;
	std::cout << max(i, j) << std::endl;
}
