/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:08:13 by taung             #+#    #+#             */
/*   Updated: 2025/09/04 14:04:21 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

# include <exception>
/*
Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be called on every element of the array.
*/
template <typename iterable, typename ret>
static void	iter(iterable *ptr, int len, ret func) {
	int	i = 0;

	while(i < len) {
		try {
			func(ptr[i]);
		} catch (const std::exception& e) {
			e.what();
		}
		i++;
	}
};

# endif
