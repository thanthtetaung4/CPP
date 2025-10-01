/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:47:59 by taung             #+#    #+#             */
/*   Updated: 2025/10/01 15:19:56 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(std::string numbers) {

	this->equation = numbers;
	// std::cout << *(numbers.end() - 1) << std::endl;
	if (*(numbers.end() - 1) == ' ' || this->isValidNumber(*(numbers.end() - 1))) {
		std::cout << "wrong input" << std::endl;
		this->eqOk = false;
	}
	else {
		if (this->isValidEquation()) {
			if (this->isValidInput()) {
				size_t	len = numbers.length();
				for (size_t i = 0; i < len; i++) {
					if (i < len - 1) {
						if (numbers[i + 1] == ' ') {
							if (!(this->isValidNumber(numbers[i]) || this->isValidOperator(numbers[i]))) {
								std::cerr << "err: not a valid number or op" << std::endl;
								this->eqOk = false;
								break;
							} else
							this->eqOk = true;
							// std::cout << numbers[i] << std::endl;
							i++;
						} else {
							std::cerr << "err: number must be 0 - 9" << std::endl;
							this->eqOk = false;
							break;
						}
					} else {
						if (!(this->isValidNumber(numbers[i]) || this->isValidOperator(numbers[i]))) {
							std::cerr << "err: not a valid number or op 2" << std::endl;
							this->eqOk = false;
							break;
						} else {
							// std::cout << numbers[i] << std::endl;
							this->eqOk = true;
						}
					}
				}
			} else {
				std::cerr << "err: wrong input" << std::endl;
				this->eqOk = false;
			}

		} else {
			std::cerr << "err: wrong equation" << std::endl;
			this->eqOk = false;
		}
	}
	// std::cout << "eq OK?: " << this->eqOk << std::endl;
	this->eqOk ? this->equation = numbers : this->equation = "";
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
			if (equation[i + 1] == ' ') {
				if (this->isValidNumber(equation[i]))
					number++;
				else if (this->isValidOperator(equation[i]))
					op++;
				// std::cout << equation[i] << std::endl;
				i++;
			}
		} else {
			if (this->isValidNumber(equation[i]))
					number++;
			else if (this->isValidOperator(equation[i]))
				op++;
		}
	}
	// std::cout << op << " , " << number - 1 << std::endl;
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

std::string	RPN::getEqueation(void) {
	return (this->equation);
}

int	RPN::pop() {
	int	i = this->rpn.top();
	this->rpn.pop();

	return (i);
}

int	RPN::exec_op(int b, int a, char op) {
	long	res = 0;
	if (op == '+')
		res = a + b;
	else if (op == '-')
		res = a - b;
	else if (op == '*')
		res = a * b;
	else if (op == '/')
		res = a / b;
	if (res > INT_MAX || res < INT_MIN)
		throw ResultOutOfLimit();
	return (static_cast<int>(res));
}

int	RPN::exec() {
	int	a = 0;

	for (size_t i = 0; i < this->equation.length(); i += 2) {
		// std::cout << this->equation[i] << std::endl;
		if (this->isValidNumber(this->equation[i])) {
			this->rpn.push(std::atoi(&this->equation[i]));
			// std::cout << "numb: " << std::atoi(&this->equation[i]) << std::endl;
		}
		if (this->isValidOperator(this->equation[i])) {
			a = this->exec_op(this->pop(), this->pop(), this->equation[i]);
			this->rpn.push(a);
		}
	}
	return (a);
}

const char* RPN::ResultOutOfLimit::what() const throw() {
	return ("Result is out of int limit");
}
