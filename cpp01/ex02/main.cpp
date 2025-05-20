/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:55:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/20 14:11:56 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "string    : " << string << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;

	std::cout << "=====================================" << std::endl;

	std::cout << "address of string    : " << &string << std::endl;
	std::cout << "address of stringREF : " << &stringREF << std::endl;
	std::cout << "address of stringPTR : " << &stringPTR << std::endl;

	std::cout << "=====================================" << std::endl;

	std::cout << "address of string and address of stringREF are" << ((&string) == (&stringREF) ? " the same" : " not the same") << std::endl;
	std::cout << "address of string and value stringPTR are" << ((&string) == (stringPTR) ? " the same" : " not the same") << std::endl;
	std::cout << "value of string and value of stringREF are" << ((string) == (stringREF) ? " the same" : " not the same") << std::endl;

	std::cout << "=====================================" << std::endl;

	string = "BRAIN THIS IS HI";

	std::cout << "string    : " << string << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;

	std::cout << "=====================================" << std::endl;

	std::cout << "address of string    : " << &string << std::endl;
	std::cout << "address of stringREF : " << &stringREF << std::endl;
	std::cout << "address of stringPTR : " << &stringPTR << std::endl;

	std::cout << "=====================================" << std::endl;

	stringREF = "BRAIN THIS IS BRAIN";

	std::cout << "string    : " << string << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;

	std::cout << "=====================================" << std::endl;

	std::cout << "address of string    : " << &string << std::endl;
	std::cout << "address of stringREF : " << &stringREF << std::endl;
	std::cout << "address of stringPTR : " << &stringPTR << std::endl;

	std::cout << "=====================================" << std::endl;

	return (0);
}
