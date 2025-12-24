/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:10:50 by taung             #+#    #+#             */
/*   Updated: 2025/12/24 22:19:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "easyfind.hpp"
# include <vector>
# include <list>
# include <deque>

int	main(void) {
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int>		lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	std::deque<int>		deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	// Test 1: Find existing element in vector
	std::cout << "=== Test 1: vector ===" << std::endl;
	try {
		std::cout << "Looking for 3 in vec: " << *easyfind(vec, 3) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test 2: Find non-existing element in vector
	std::cout << "\n=== Test 2: vector (not found) ===" << std::endl;
	try {
		std::cout << "Looking for 42 in vec: " << *easyfind(vec, 42) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test 3: Find existing element in list
	std::cout << "\n=== Test 3: list ===" << std::endl;
	try {
		std::cout << "Looking for 20 in lst: " << *easyfind(lst, 20) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test 4: Find existing element in deque
	std::cout << "\n=== Test 4: deque ===" << std::endl;
	try {
		std::cout << "Looking for 200 in deq: " << *easyfind(deq, 200) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test 5: Empty container
	std::cout << "\n=== Test 5: empty container ===" << std::endl;
	std::vector<int>	empty;
	try {
		std::cout << "Looking for 1 in empty: " << *easyfind(empty, 1) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
