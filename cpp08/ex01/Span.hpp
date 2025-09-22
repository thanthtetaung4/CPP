/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:35:05 by taung             #+#    #+#             */
/*   Updated: 2025/09/11 23:19:50 by taung            ###   ########.fr       */
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
		unsigned int	_N;
		std::vector<int>	_container;
	public:
		Span(void);
		Span(int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int i);
		template<typename Iterator>
		void	addNumber(Iterator begin, Iterator end) {
			for (Iterator it = begin; it != end; ++it) {
				addNumber(*it);
			}
		}
		int		shortestSpan(void);
		int		longestSpan(void);
		const std::vector<int>&	getContainer(void) const;
		int		getN(void) const;

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
};
std::ostream&	operator<<(std::ostream& os, Span sp);

# endif
