/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:17:44 by taung             #+#    #+#             */
/*   Updated: 2025/04/09 11:03:50 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SIFL.h"

void	sed(std::string filename, std::string s1, std::string s2) {
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		line;
	int				startAt;

	inFile.open((filename.c_str()));
	if (s1.length() < 1 || s2.length() < 1)
	{
		std::cout << "empty s1 or s2 is invalid" << std::endl;
		return;
	}
	if (inFile.is_open()) {
		if (getline (inFile, line)) {
			outFile.open((filename + ".replace").c_str());
			if (outFile.is_open()) {
				std::cout << "writing lines from " + filename + " to " + filename + ".replace" << std::endl;
				do {
					startAt = line.find(s1);
					while (startAt != -1)
					{
						line.erase(startAt,s1.length());
						line.insert(startAt, s2);
						startAt = line.find(s1);
					}
					outFile << line << std::endl;
				} while (getline (inFile, line));
				inFile.close();
				outFile.close();
				std::cout << std::endl;
				std::cout << "done writing" << std::endl;
			}
			else {
				std::cout << "cannot create output file" << std::endl;
			}
		}
		else {
			std::cout << "file is empty" << std::endl;
		}
	}
	else {
		std::cout << "could not open the file" << std::endl;
	}
}
