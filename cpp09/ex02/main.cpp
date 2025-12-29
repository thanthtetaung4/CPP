/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:31:51 by taung             #+#    #+#             */
/*   Updated: 2025/12/30 01:07:20 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"
# include <iomanip>
# include <sys/time.h>
# include <cstdio>

double	get_time_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

int	main(int ac, char *av[]) {
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try {
		PmergeMe PM(av + 1);

		// Time the deque operation
		double start_dq = get_time_us();
		PM.dqOp();
		double end_dq = get_time_us();
		double duration_dq = end_dq - start_dq;

		// Time the vector operation
		double start_v = get_time_us();
		PM.vOp();
		double end_v = get_time_us();
		double duration_v = end_v - start_v;

		// Display results after sorting
		PM.displayResults();

		// Display timing with proper precision
		char	buffer_v[100];
		char	buffer_dq[100];

		snprintf(buffer_v, sizeof(buffer_v), "%.5f", duration_v / 1000.0);
		snprintf(buffer_dq, sizeof(buffer_dq), "%.5f", duration_dq / 1000.0);

		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::vector : "
				  << buffer_v << " us" << std::endl;
		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::deque : "
				  << buffer_dq << " us" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}

