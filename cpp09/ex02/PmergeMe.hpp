/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:02:31 by taung             #+#    #+#             */
/*   Updated: 2025/12/31 01:02:33 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class Merge {
	private:
		std::vector<int> _vectorData;
		std::deque<int> _dequeData;
	public:
		Merge();
		Merge(const Merge& other);
		Merge& operator= (const Merge& other);
		~Merge();

		void program(int ac, char** av);
		void checkInput(int ac, char** av);
		template<typename T>
		void Display(const std::string& str, const T& data);
		std::vector<int> magic(std::vector<int>& data);
		std::deque<int> magicD(std::deque<int> & data);
};

# endif
