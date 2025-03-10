/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:10:34 by taung             #+#    #+#             */
/*   Updated: 2025/03/11 01:10:52 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AWPB.hpp"

std::string formatColumn(std::string str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";  // Truncate and replace last character with '.'
	}
	return std::string(10 - str.length(), ' ') + str;  // Right-align
}
