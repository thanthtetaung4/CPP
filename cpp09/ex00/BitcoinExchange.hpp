/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:46 by taung             #+#    #+#             */
/*   Updated: 2025/12/29 20:28:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BTC_HPP
# define BTC_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <fstream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <limits>
# include <regex.h>
# include <limits>

class BitcoinExchange {
	private:
		std::map<std::string, float>	record;
		bool	checkDate(const std::string& date);
		bool	checkValue(float value);
		void	exchange(const std::string& date, double btc);
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		void	getExchange(const std::string& path);
		const std::string	getRecord(void) const;
};
std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& btc);

# endif
