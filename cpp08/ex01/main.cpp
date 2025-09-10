/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:35:11 by taung             #+#    #+#             */
/*   Updated: 2025/09/10 21:38:51 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <vector>
# include "Span.hpp"

int main() {
	Span	sp(5);

	sp.addNumber(10);
	sp.addNumber(11);
	sp.addNumber(12);
	sp.addNumber(13);
	// sp.addNumber(14);

	Span sp_cp = sp;

	std::cout << "sp\n" << sp << std::endl;
	sp_cp.addNumber(14);
	std::cout << "sp_cp\n" << sp_cp << std::endl;
	std::cout << "sp\n" << sp << std::endl;

}
