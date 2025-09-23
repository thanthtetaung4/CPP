/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:46 by taung             #+#    #+#             */
/*   Updated: 2025/09/23 16:48:33 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BTC_HPP
# define BTC_HPP

# include <iostream>
# include <algorithm>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, int>	record;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		long	exchange(std::string date, int btc);

};

# endif
