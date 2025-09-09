/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:10:54 by taung             #+#    #+#             */
/*   Updated: 2025/09/09 19:27:25 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	* @brief Finds the key in container.
	*
	* This function finds the key in the container and return true if the key is in the container and false if the key is not in the container.
		Since the key is int, passing string container will cause compliation error.
	*
	* @param container The container object.
	* @param key The key to find in the container.
	* @return Boolean 'true' or 'false'
*/
template <typename T>
bool	easyfind(T container, int key) {
	if (container.size() == 0)
		return (false);
	if (std::find(container.begin(), container.end(), key) != container.end())
		return (true);
	else
		return (false);
}
