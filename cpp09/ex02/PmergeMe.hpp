/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:31:40 by taung             #+#    #+#             */
/*   Updated: 2025/10/02 17:46:00 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PM_HPP
# define PM_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <exception>

class PmergeMe {
	private:
		std::deque<int>	dq;
		std::vector<int>	v;
		template<typename container>
		void	sort(container c);
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe(char *numbers[]);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	dqOp(void);
		void	vOp(void);
		void	parseNumbers(char* av[]);
		class NotANumber : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};


# endif
