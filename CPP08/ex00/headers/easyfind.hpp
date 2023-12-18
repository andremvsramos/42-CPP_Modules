/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:55:31 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/18 17:49:58 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class WrongElement : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Element not in container");
		};
};

# include "../src/easyfind.tpp"

template <typename T>
void easyfind(const T & container, int toFind);

#endif
