/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:19:24 by taung             #+#    #+#             */
/*   Updated: 2025/03/27 17:01:34 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void	Harl::debug( void ) {
	std::cout << "[DEBUG]"
		<< std::endl
		<< "I love having extra bacon for my"
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void	Harl::info( void ) {
	std::cout << "[INFO]"
		<< std::endl
		<< "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[WARNING]"
		<< std::endl
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
		<< "years, whereas you started working here just last month."
		<< std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ERROR]"
		<< std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain(std::string level) {
		const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void (Harl::*funcs[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

		for (int i = 0; i < 4; ++i) {
			if (level == levels[i]) {
				(this->*funcs[i])();
				return;
			}
		}
		std::cout << "[INVALID]"
			<< std::endl
			<< "Invalid complaint level!" << std::endl;
}
