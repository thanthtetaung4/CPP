/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:37:42 by taung             #+#    #+#             */
/*   Updated: 2025/09/02 17:03:42 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
static void	swap(T& a, T& b) {
	T	tmp = a;
	a = b;
	b = tmp;
};

template<typename T>
static const T&	min(T& a, T& b) {
	return (a < b ? a : b);
};

template<typename T>
static const T&	max(T& a, T& b) {
	return (a > b ? a : b);
};

# endif
