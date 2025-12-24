/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:35:05 by taung             #+#    #+#             */
/*   Updated: 2025/12/24 22:23:08 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <iostream>
# include <algorithm>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_container;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int i);
		template<typename Iterator>
		void	addRange(Iterator begin, Iterator end) {
			while (begin != end) {
				addNumber(*begin);
				++begin;
			}
		}
		int		shortestSpan(void);
		int		longestSpan(void);
		const std::vector<int>&	getContainer(void) const;
		unsigned int	getN(void) const;

		// Exception
		class IvalidN : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Can't init the class with N zero";
			}
		};

		class ContainerIsFull : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Container is full";
			}
		};

		class NotEnoughElements : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Not enough elements to find span";
			}
		};
};
std::ostream&	operator<<(std::ostream& os, const Span& sp);

# endif
