/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:40:40 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 00:37:17 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main() {
	Data		*data = new Data("top secret");
	uintptr_t	ptr = Serializer::serialize(data);

	std::cout << Serializer::serialize(data) << " and " << ptr << std::endl;
	std::cout << Serializer::deserialize(ptr)->getSecret() << " and " << data->getSecret() << std::endl;
	std::cout << (data == (Serializer::deserialize(ptr)) )<< std::endl;

	//why is this so dangerous
	// ptr++;
	// std::cout << Serializer::deserialize(ptr)->getSecret() << " and " << data->getSecret() << std::endl;
}
