/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:10:59 by taung             #+#    #+#             */
/*   Updated: 2025/12/24 22:19:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, int key);

# include "easyfind.tpp"

# endif
