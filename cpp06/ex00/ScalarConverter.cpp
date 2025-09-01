/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:06:31 by taung             #+#    #+#             */
/*   Updated: 2025/09/01 21:07:53 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include <typeinfo>
# include <cmath>
# include <iomanip>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
	(void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
	(void)other;
	return (*this);
}

/*
	invalid
		- "nan" (characters)
		- "a12" (all number with one or more characters)
		=> len > 1 and has one or more characters
	valid
		- "a" (single char as a string)
		- "1341234" (all number string)
		=> len 1 with char
		=> len > 1 without char
*/
bool	isValidStr(std::string value) {
	int	dotCount = 0;
	int	fCount = 0;

	if (value.length() > 1)
	{
		for (size_t i = 0; ((i < value.length()) && (dotCount < 2) && (fCount < 2)); i++) {
			if (!std::isdigit(value[i])) {
				if (value[i] == 'f')
					fCount++;
				else if (value[i] == '.')
					dotCount++;
				else
					return (false);
			}
		}
		return (((dotCount < 2) && (fCount < 2)) && (fCount <= dotCount));
	}
	return (true);
}

void	convertStr(double dval) {
	if (dval < 32 || dval > 126) {
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: " << static_cast<char>(dval) << std::endl;
}

void	convertInt(double dval) {
	if (dval > std::numeric_limits<int>::max() || dval < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(dval) << std::endl;
}

void	convertFloat(double dval) {
	if (dval > std::numeric_limits<float>::max() || dval < std::numeric_limits<float>::min()) {
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	float tmp = 0;
	tmp = static_cast<float>(dval);
	if (fmod(tmp, static_cast<int>(tmp)) == 0)
		std::cout << std::fixed << std::setprecision(1) << "float: " << tmp << "f" << std::endl;
	else
		std::cout << "float: " << tmp << "f" << std::endl;
}

void	convertDouble(double dval) {
	if (dval > std::numeric_limits<double>::max() || dval < std::numeric_limits<double>::min()) {
		std::cout << "double: nan" << std::endl;
		return ;
	}
	std::cout << "double: " << dval << std::endl;
}

bool	isInf(std::string value) {
	if (value == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return (true);
	}
	else if (value == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
	return (false);
}

void ScalarConverter::convert(std::string value) {

	if (isInf(value))
		return ;
	if (!isValidStr(value)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else {
		double	dval;
		dval = (std::atof((value.c_str())));
		convertStr(dval);
		convertInt(dval);
		convertFloat(dval);
		convertDouble(dval);
	}
}
