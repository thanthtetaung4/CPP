/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:35:55 by taung             #+#    #+#             */
/*   Updated: 2025/09/04 16:52:42 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>
/*
	I need two overloads for the [], indexing.
		- T&	operator[] (unsigned int index);
		- const T&	operator[] (unsigned int index) const;
*/
template <typename T>
class Array {
	private:
		T *_array;
		unsigned int _size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int size() const;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &arr);

# include "Array.tpp"

#endif
