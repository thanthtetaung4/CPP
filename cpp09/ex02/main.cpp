/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 00:59:59 by taung             #+#    #+#             */
/*   Updated: 2025/12/31 01:00:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"
# include <exception>
# include <iostream>

int main(int ac, char **av)
{
	try{
		Merge a;
		a.program(ac, av);
		return 0;
	}
	catch(const std::exception& e){
		std::cerr << "Error: "<< e.what() <<std::endl;
	}
	return 1;
}
