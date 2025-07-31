/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:21 by taung             #+#    #+#             */
/*   Updated: 2025/07/31 18:59:51 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void) {

}
