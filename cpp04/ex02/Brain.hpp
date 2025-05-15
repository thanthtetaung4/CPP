/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:20:54 by taung             #+#    #+#             */
/*   Updated: 2025/05/09 17:19:32 by taung            ###   ########.fr       */
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
		Brain(Brain &other);
		Brain& operator=(const Brain &other);
		~Brain(void);
		void		setIdea(std::string idea, const int index);
		std::string	getIdea(const int index) const;
};

#endif
