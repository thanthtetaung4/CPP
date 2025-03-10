/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:18:15 by taung             #+#    #+#             */
/*   Updated: 2025/03/11 01:51:59 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
# include "./AWPB.hpp"

class Contact {
	private:
		int	isSet;
		std::string firstName;
		std::string lastName;
		std::string nickName;

	public:
		Contact (std::string fName="fname", std::string lName="lname", std::string nName="nName");
		int	getIsSet(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		void	setIsSet(int set);
		void	setFirstName(std::string fname);
		void	setLastName(std::string lname);
		void	setNickName(std::string nname);
		void	updateContact(std::string fName, std::string lName, std::string nName);
};

#endif
