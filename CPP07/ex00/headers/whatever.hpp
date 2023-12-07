/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:48:04 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 14:12:21 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T & a, T & b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T & a, T & b) {
	return (a < b ? a : b);
}

template <typename T>
T	max(T & a, T & b) {
	return (a > b ? a : b);
}

#endif
