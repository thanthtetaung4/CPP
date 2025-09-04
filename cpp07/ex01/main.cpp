/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:07:40 by taung             #+#    #+#             */
/*   Updated: 2025/09/04 13:59:49 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "iter.hpp"

template <typename data>
void	print(const data d) {
	std::cout << d << std::endl;
}

int	add(int &i) {
	i++;
	return (1);
}

int	main() {
	int	arr[5] = {1, 2, 3, 4, 5};
	char	carr[5] = {'a', 'b', 'c', 'd', 'e'};

	iter(arr, 5, add);
	iter(arr, 5, print<int>);
	iter(carr, 5,print<char>);
}
