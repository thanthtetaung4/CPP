/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:19:24 by taung             #+#    #+#             */
/*   Updated: 2025/03/28 12:03:45 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void	Harl::debug( void ) {
	std::cout << "[DEBUG]"
		<< std::endl
		<< "I love having extra bacon for my"
		<< " 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< std::endl
		<< "I really do!"
		<< std::endl;
}

void	Harl::info( void ) {
	std::cout << "[INFO]"
		<< std::endl
		<< "I cannot believe adding extra bacon costs more money."
		<< std::endl
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[WARNING]"
		<< std::endl
		<< "I think I deserve to have some extra bacon for free."
		<< std::endl
		<< "I’ve been coming for years, whereas you started working here just last month."
		<< std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ERROR]"
		<< std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

int		getLevel(std::string level, const std::string levels[]) {
	for (int i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			return (i);
		}
	}
	return (-1);
}

void	Harl::complain(std::string level) {
		const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void				(Harl::*funcs[])(void) = { &Harl::debug, &Harl::info,
														&Harl::warning, &Harl::error };
		const int			hlevel = getLevel(level, levels);

		switch (hlevel)
		{
		case 0:
			(this->*funcs[0])();
			std::cout << std::endl;
		case 1:
			(this->*funcs[1])();
			std::cout << std::endl;
		case 2:
			(this->*funcs[2])();
			std::cout << std::endl;
		case 3:
			(this->*funcs[3])();
			break;
		default:
			std::cout << "[INVALID]"
			<< std::endl
			<< "Invalid complaint level!" << std::endl;
			break;
		}

}
