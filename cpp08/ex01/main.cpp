/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:35:11 by taung             #+#    #+#             */
/*   Updated: 2025/12/24 22:23:08 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <vector>
# include <array>
# include "Span.hpp"

// Subject's main
int	main(void) {

	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::array<int, 10>		arr = {10, 15, 14 ,12, 1, 18, 2, 57, 16, 0};
		Span	sp2 = Span(20);
		Span	sp1 = Span(1);

		sp1.addNumber(10);

		sp2.addRange(arr.begin(), arr.end());
		std::cout << sp2 << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		sp1 = sp2;
		std::cout << sp1 << std::endl;
		sp2.addNumber(11);
		std::cout << "===sp1===" << std::endl;
		std::cout << sp1 << std::endl;
		std::cout << "===sp2===" << std::endl;
		std::cout << sp2 << std::endl;
	}

	return 0;
}
