/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:44:14 by taung             #+#    #+#             */
/*   Updated: 2025/09/22 17:51:13 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <sstream>

/*
	Needs to follow the template of the std::stack
*/
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	// In C++98, you must explicitly declare constructors if needed
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
	MutantStack &operator=(const MutantStack &other) {
		std::stack<T, Container>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// Iterator access
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};
template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os, const MutantStack<T, Container>& mt) {
	typename MutantStack<T, Container>::const_iterator it;
	for (it = mt.begin(); it != mt.end(); ++it) {
		os << *it << " ";
	}
	return os;
}

# endif
