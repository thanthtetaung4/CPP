/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:02:22 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 14:41:21 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits.h>
# include <limits>

/*
if possible convert else error

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/

# define FLOAT_MIN_POSITIVE 1.17549435e-38f
# define DOUBLE_MIN_POSITIVE 2.2250738585072014e-308

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter& other);
		ScalarConverter& operator=(ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(std::string value);
};

# endif
