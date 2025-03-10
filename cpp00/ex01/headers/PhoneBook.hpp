/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:18:47 by taung             #+#    #+#             */
/*   Updated: 2025/03/11 01:14:15 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"
#include "./AWPB.hpp"

class PhoneBook {
	private:
		int		oldest;
		int		count;
		Contact	contacts[8];

	public:
		PhoneBook();
		void	searchContact(int index);
		void	setContact(int index, std::string fName, std::string lName, std::string nName);
		void	addContact(std::string fName, std::string lName, std::string nName);
};

#endif
