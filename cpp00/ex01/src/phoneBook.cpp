/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:40:30 by taung             #+#    #+#             */
/*   Updated: 2025/03/11 02:09:16 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AWPB.hpp"

PhoneBook::PhoneBook() {
	oldest = 0;
	count = 0;
}

void	PhoneBook::searchContact(int index) {
	std::string	fname;
	std::string	lname;
	std::string	nname;

	if (index > 8 || index < 1)
	{
		std::cout << "!!INDEX OUT OF RANGE [1-8]!!" << std::endl;
		return ;
	}
	if (contacts[index - 1].getIsSet())
	{
		fname = contacts[index - 1].getFirstName();
		lname = contacts[index - 1].getLastName();
		nname = contacts[index - 1].getNickName();
		std::cout << std::setw(10) << index << "|"
				<< formatColumn(fname) << "|"
				<< formatColumn(lname) << "|"
				<< formatColumn(nname) << std::endl;
	}
	else {
		std::cout << "!!CONTACT AT " << index - 1 << " IS EMPTY!!" << std::endl;
	}
}

void	PhoneBook::setContact(int index, std::string fName, std::string lName, std::string nName) {
	if (index >= 0 && index < 8) {
		contacts[index].updateContact(fName, lName, nName);
	}
	else
		std::cerr << "Wrong!! " << index;
}

void	PhoneBook::addContact(std::string fName, std::string lName, std::string nName)
{
	if (count < 8) {
		setContact(count, fName, lName, nName);
		count ++;
	}
	else {
		std::cout << (count - oldest) % 8;
		setContact((oldest) % 8, fName, lName, nName);
		oldest++;
	}
}

