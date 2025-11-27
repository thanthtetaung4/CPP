/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:31:47 by taung             #+#    #+#             */
/*   Updated: 2025/10/02 17:51:58 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char *numbers[]) {
	parseNumbers(numbers);

	std::cout << "vector" << std::endl;
	for (std::vector<int>::iterator it = this->v.begin(); it != this->v.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << "deque" << std::endl;
	for (std::deque<int>::iterator it = this->dq.begin(); it != this->dq.end(); it++) {
		std::cout << *it << std::endl;
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other) {
		this->dq = other.dq;
		this->v = other.v;
	}
	return (*this);
}

const char* PmergeMe::NotANumber::what() const throw() {
	return ("Not a number");
}


void	PmergeMe::parseNumbers(char* av[]) {
	for (size_t i = 0; av[i]; i++) {
		if (std::isdigit(*av[i])) {
			this->v.push_back(std::atoi(av[i]));
			this->dq.push_back(std::atoi(av[i]));
		}
		else {
			// std::cout << "wtf" << std::endl;
			throw PmergeMe::NotANumber();
		}
	}
}

void	PmergeMe::dqOp(void) {
	sort(this->dq);
}

void	PmergeMe::vOp(void) {
	sort(this->v);
}

template<typename container>
void	PmergeMe::sort(container c) {
	typename container::iterator	it;

	for (it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
