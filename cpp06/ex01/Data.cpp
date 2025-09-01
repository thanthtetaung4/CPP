/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:48:53 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 00:33:18 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"

Data::Data() : secret("not secret") {}

Data::Data(const std::string& secret) {
	this->secret = secret;
}


Data::Data(Data& other) {
	if (this != &other) {
		*this = other;
	}
}

Data& Data::operator=(Data& other) {
	if (this != &other) {
		this->secret = other.secret;
	}
	return (*this);
}

Data::~Data() {}

const std::string&	Data::getSecret(void) const {
	return (this->secret);
}

