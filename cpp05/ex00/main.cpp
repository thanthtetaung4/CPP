/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:20:43 by taung             #+#    #+#             */
/*   Updated: 2025/07/31 19:28:18 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"

int	main(void){
	try {
		Bureaucrat	b("name", 200);
	} catch (const std::exception e) {
		std::cout << e.what() << std::endl;
	}
}
