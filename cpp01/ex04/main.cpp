/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:05:09 by taung             #+#    #+#             */
/*   Updated: 2025/03/25 15:34:31 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SIFL.h"

int	main(int argc, char **argv) {
	if (argc != 4)
		std::cerr << "<filename> <s1> <s2> required" << std::endl;
	else
		sed(argv[1], argv[2], argv[3]);
}
