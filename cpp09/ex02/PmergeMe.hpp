/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:31:40 by taung             #+#    #+#             */
/*   Updated: 2025/12/22 00:53:51 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PM_HPP
# define PM_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <exception>
# include <ctime>
# include <sys/time.h>
# include <algorithm>
# include <string>

class PmergeMe {
	private:
		std::deque<int>	dq;
		std::vector<int>	v;
		std::vector<int>	unsorted;

		// Ford-Johnson sort for vector
		void	sortVector();
		void	mergeInsertVector(std::vector<int>& arr);
		void	mergeVector(std::vector<int>& arr, int left, int mid, int right);

		// Ford-Johnson sort for deque
		void	sortDeque();
		void	mergeInsertDeque(std::deque<int>& arr);
		void	mergeDeque(std::deque<int>& arr, int left, int mid, int right);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe(char *numbers[]);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	dqOp(void);
		void	vOp(void);
		void	parseNumbers(char* av[]);
		void	displayResults(void);

		class NotANumber : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidInput : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

# endif
