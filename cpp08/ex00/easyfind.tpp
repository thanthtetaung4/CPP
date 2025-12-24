/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:10:54 by taung             #+#    #+#             */
/*   Updated: 2025/12/24 22:19:44 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	* @brief Finds the first occurrence of key in container.
	*
	* This function finds the first occurrence of the key in the container
	* and returns an iterator to it. Throws an exception if not found.
	*
	* @param container The container object (reference).
	* @param key The key to find in the container.
	* @return Iterator to the found element.
	* @throws std::runtime_error if element is not found.
*/
template <typename T>
typename T::iterator	easyfind(T& container, int key) {
	typename T::iterator it = std::find(container.begin(), container.end(), key);
	if (it == container.end())
		throw std::runtime_error("Element not found in container");
	return it;
}
