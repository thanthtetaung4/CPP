/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:40:17 by taung             #+#    #+#             */
/*   Updated: 2025/05/07 21:03:29 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain {
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain&			operator=(const Brain& other);
		~Brain();
		void			setIdea(std::string idea, int ideaNumber);
		std::string		getIdea(int ideaNumber) const;
		std::string*	getIdeas(void);
		void			displayIdeas(void) const;
};

#endif
