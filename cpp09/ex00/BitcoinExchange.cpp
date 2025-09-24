/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:48 by taung             #+#    #+#             */
/*   Updated: 2025/09/24 21:35:52 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	std::ifstream inputFile("data.csv");

	if (!inputFile.is_open()) {
		std::cerr << "Error opening my_data.txt!" << std::endl;
		return;
	}

	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		std::string::size_type pos = line.find(',');
		std::cout << line << std::endl;
		if (pos != std::string::npos) {
			std::string date = line.substr(0, pos);
			float value = std::atof((line.substr(pos + 1)).c_str());

			if (this->checkDate(date) && this->checkValue(value))
				this->record.insert(std::pair<std::string, int>(date, value));
			else
			{
				std::cerr << "Wrong Format!" << std::endl;
				break;
			}
		} else {
			std::cerr << "Wrong Format!" << std::endl;
			break;
		}
	}

	inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->record = other.record;
	}
	return (*this);
}

void	BitcoinExchange::exchange(std::string date, int btc) {
	std::cout << date << btc << std::endl;
	if (this->checkDate(date) && btc > 0 && btc < INT8_MAX) {
		std::map<std::string, float>::iterator it = this->record.lower_bound(date);
		if (it == this->record.begin() && it->first != date) {
			throw std::runtime_error("No earlier date available");
		}
		if (it == this->record.end() || it->first != date) {
			--it;
		}
		std::cout << date << " => " << btc << " = " << (it->second * btc) << std::endl;
	}
	else {
		if (btc < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (!this->checkDate(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (btc > INT8_MAX)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << "Error: unknown error." << std::endl;
	}
}

void	loadData(std::string path) {
	(void)path;
}

const std::string	BitcoinExchange::getRecord(void) const {
	std::string	records = "";

	for (std::map<std::string, float>::const_iterator i = this->record.begin(); i != this->record.end(); i++) {
		std::stringstream ss;
		ss << i->second;
		records.append(i->first + " : " + ss.str() + "\n");
	}
	return (records);
}

std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& btc) {
	os << btc.getRecord();

	return (os);
}

bool isLeapYear(int year) {
	return ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) );
}

bool isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false; // must be "YYYY-MM-DD"
	}

	int year, month, day;
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());

	// --- check ranges ---
	if (year < 1 || year > 9999) return false;
	if (month < 1 || month > 12) return false;

	// Days per month
	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30,
							31, 31, 30, 31, 30, 31 };

	// February leap year adjustment
	if (month == 2 && isLeapYear(year))
		daysInMonth[2] = 29;

	if (day < 1 || day > daysInMonth[month]) return false;

	return true;
}

bool	BitcoinExchange::checkDate(std::string date) {
	const char *pattern = "^[0-9]{4}-[0-9]{2}-[0-9]{2}$";
	regex_t regex;
	int ret;

	ret = regcomp(&regex, pattern, REG_EXTENDED);
	if (ret) {
		std::cerr << "Could not compile regex\n";
		return (false);
	}

	ret = regexec(&regex, date.c_str(), 0, NULL, 0);
	if (!ret && isValidDate(date)) {
		return (true);
	} else {
		return (false);
	}
}

bool	BitcoinExchange::checkValue(float value) {
	if (value > std::numeric_limits<float>::max() || value < 0)
		return (false);
	return (true);
}

void	BitcoinExchange::getExchange(std::string path) {
	std::ifstream inputFile(path);

	if (!inputFile.is_open()) {
		std::cerr << "Error opening my_data.txt!" << std::endl;
		return;
	}

	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		std::string::size_type pos = line.find('|');
		// std::cout << line << std::endl;
		if (pos != std::string::npos) {
			std::string date = line.substr(0, pos);
			int value = std::atoi((line.substr(pos + 1)).c_str());

			this->exchange(date, value);
		}
	}

	inputFile.close();
}
