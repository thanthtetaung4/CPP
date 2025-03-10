/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:44:22 by taung             #+#    #+#             */
/*   Updated: 2025/03/11 01:52:24 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AWPB.hpp"

Contact::Contact (std::string fName, std::string lName, std::string nName) {
	firstName = fName;
	lastName = lName;
	nickName = nName;
	isSet = 0;
}
int	Contact::getIsSet(void) {
	return isSet;
}
std::string Contact::getFirstName(void) {
	return firstName;
}
std::string Contact::getLastName(void) {
	return lastName;
}
std::string Contact::getNickName(void) {
	return nickName;
}
void	Contact::setIsSet(int set) {
	isSet = set;
}
void Contact::setFirstName(std::string fName) {
	firstName = fName;
}
void Contact::setLastName(std::string lName) {
	lastName = lName;
}
void Contact::setNickName(std::string nName) {
	nickName = nName;
}

void Contact::updateContact(std::string fName, std::string lName, std::string nName) {
	firstName = fName;
	lastName = lName;
	nickName = nName;
	isSet = 1;
}
