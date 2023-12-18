/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:08:39 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/18 17:56:35 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
void easyfind(const T & container, int toFind) {
	(std::find(container.begin(), container.end(), toFind) != container.end()) ?
		(std::cout << "Found element in container" << std::endl) : throw WrongElement();
}

#endif
