/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:17:44 by taung             #+#    #+#             */
/*   Updated: 2025/05/20 21:50:17 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SIFL.h"

/*
function sed(filename, s1, s2):
	if filename is empty
		print  "filename is invalid"
		return

	if s1 is empty or s2 is empty:
		print "empty s1 or s2 is invalid"
		return

	open input file (filename) for reading
	if input file cannot be opened:
		print "could not open the file"
		return

	if input file is empty:
		print "file is empty"
		close input file
		return

	create and open output file (filename + ".replace") for writing
	if output file cannot be created:
		print "cannot create output file"
		close input file
		return

	for each line in the input file:
		while s1 is found in the line:
			replace s1 with s2 in the line
		write the modified line to the output file

	close input file
	close output file
	print "done writing"
*/
void	sed(std::string filename, std::string s1, std::string s2) {
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		line;
	int				startAt;

	if (filename.length() < 1) {
		std::cout << "empty filename is invalid" << std::endl;
		return;
	}
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
