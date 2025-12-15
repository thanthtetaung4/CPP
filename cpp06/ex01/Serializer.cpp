/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:41:51 by taung             #+#    #+#             */
/*   Updated: 2025/11/28 20:46:09 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(Serializer& other) {
	(void)other;
}

Serializer& Serializer::operator=(Serializer& other) {
	(void)other;
	return (*this);
}

Serializer::~Serializer() {}

/*
	Type cast the Data* to uintptr_t using reinterpret cast
	@param ptr to an instance of Data Class
	@return the ptr reinterpreted into a uintptr_t
*/
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

/*
	Type cast the raw uintptr_t to Data* using reinterpret cast
	@param raw uintptr_t
	@return the raw reinterpreted into the Data*
*/
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
