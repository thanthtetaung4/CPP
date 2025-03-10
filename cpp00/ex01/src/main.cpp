/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:17:45 by taung             #+#    #+#             */
/*   Updated: 2025/03/11 02:08:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AWPB.hpp"

int main(void) {
	std::cout << "HELLO\n";
	PhoneBook	pb;
	std::string	userInput = "START";
	std::string	fname;
	std::string	lname;
	std::string	nname;
	int			index;

	pb.addContact("1","b","d");
	pb.addContact("2","b","d");
	pb.addContact("3","b","d");
	pb.addContact("4","b","d");
	pb.addContact("5","b","d");
	pb.addContact("6","b","d");
	pb.addContact("7","b","d");
	pb.addContact("8","b","d");
	while (1) {
		std::cout << "Choose the mode you want: \n\tEXIT \n\tADD \n\tSEARCH" << std::endl;
		std::cin >> userInput;
		if (userInput == "EXIT") {
			std::cout << "===== BYE =====" << std::endl;
			break;
		}
		else if (userInput == "ADD") {
			std::cout << "Enter First Name: ";
			std::cin >> fname;
			std::cout << "Enter Last Name: ";
			std::cin >> lname;
			std::cout << "Enter Nick Name: ";
			std::cin >> nname;
			pb.addContact(fname, lname, nname);
		}
		else if (userInput == "SEARCH") {
			std::cout << "Enter the index you want to search: ";
			std::cin >> index;
			pb.searchContact(index);
		}
	}
	return (0);
}
