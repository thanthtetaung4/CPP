/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:48:49 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 00:26:21 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	public:
		Data();
		Data(const std::string& secret);
		Data(Data& other);
		Data& operator=(Data& other);
		~Data();
		const std::string&	getSecret(void) const;
	private:
		std::string	secret;
};

# endif
