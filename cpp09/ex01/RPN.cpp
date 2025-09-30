/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:47:59 by taung             #+#    #+#             */
/*   Updated: 2025/09/30 18:55:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(std::string numbers) {
	this->equation = numbers;
	std::cout << this->isValidEquation() << std::endl;
	std::cout << this->isValidInput() << std::endl;
	// size_t	len = numbers.length();
	// for (size_t i = 0; i < len; i++) {
	// 	if (i < len - 1) {
	// 		if (numbers[i + 1] == ' ') {
	// 			std::cout << numbers[i] << std::endl;
	// 			i++;
	// 		}
	// 	} else
	// 		std::cout << numbers[i] << std::endl;
	// }
}

bool	RPN::isValidOperator(char c) {
	if (c == '+')
		return (true);
	else if (c == '-')
		return (true);
	else if (c == '*')
		return (true);
	else if (c == '/')
		return (true);
	return (false);
}

bool	RPN::isValidNumber(char c) {
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	RPN::isValidEquation(void) {
	size_t	len = equation.length();
	int		number = 0;
	int		op = 0;

	for (size_t i = 0; i < len; i++) {
		if (i < len - 1) {
			if (equation[i + 1] == ' ' && this->isValidOperator(equation[i])) {
				if (this->isValidNumber(equation[i]))
					number++;
				else if (this->isValidOperator(equation[i]))
					op++;
				std::cout << equation[i] << std::endl;
				i++;
			}
		} else {
			if (this->isValidNumber(equation[i]))
					number++;
			else if (this->isValidOperator(equation[i]))
				op++;
		}
	}
	std::cout << op << " , " << number - 1 << std::endl;
	return (op == (number - 1));
}

bool	RPN::isValidInput(void) {
	if (this->equation.length() < 5)
		return (false);
	if (!(this->isValidNumber(this->equation[0])) && !(this->isValidNumber(this->equation[2])))
		return (false);
	return (true);
}


RPN::RPN(const RPN& other) {
	*this = other;
}

const RPN&	RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->rpn = other.rpn;
	}
	return (*this);
}

RPN::~RPN() {}
