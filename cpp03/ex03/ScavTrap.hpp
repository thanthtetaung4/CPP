/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:04:20 by taung             #+#    #+#             */
/*   Updated: 2025/05/31 14:29:17 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	private:
		const std::string	myName(void) const;
		static const unsigned int	defaultEP = 50;
	protected:
		unsigned int	getDefaultEP(void) const;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap& other);
		void		attack(const std::string& target);
		void		guardGate(void);
};
