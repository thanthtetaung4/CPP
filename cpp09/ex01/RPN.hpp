/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:48:06 by taung             #+#    #+#             */
/*   Updated: 2025/09/30 18:22:49 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
	private:
		std::stack<int>	rpn;
		std::string	equation;
		bool	isValidInput(void);
		bool	isValidOperator(char c);
		bool	isValidNumber(char c);
		bool	isValidEquation(void);
	public:
		RPN(void);
		RPN(std::string numbers);
		RPN(const RPN& other);
		const RPN&	operator=(const RPN& other);
		~RPN();
};

# endif
