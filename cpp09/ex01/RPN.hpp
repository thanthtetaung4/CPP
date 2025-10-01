/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:48:06 by taung             #+#    #+#             */
/*   Updated: 2025/10/01 15:04:09 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <climits>
# include <exception>

class RPN {
	private:
		std::stack<int>	rpn;
		std::string	equation;
		bool		eqOk;
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
		std::string	getEqueation(void);
		int	exec();
		int	pop();
		int	exec_op(int a, int b, char op);
		class ResultOutOfLimit : public std::exception {
			public:
			virtual const char* what() const throw();
		};

};

# endif
