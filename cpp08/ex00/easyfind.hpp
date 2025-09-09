/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:10:59 by taung             #+#    #+#             */
/*   Updated: 2025/09/09 18:42:42 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <unordered_set>
# include <typeinfo>
# include <algorithm>

template <typename T>
bool	easyfind(T container, int key);

# include "easyfind.tpp"

# endif
