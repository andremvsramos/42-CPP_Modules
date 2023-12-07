/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:48:04 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 14:12:15 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	address(T a) {
	std::cout << "Content is: " << a << std::endl;
	std::cout << "Address is: " << &a << std::endl;
}

template <typename T>
void	iter(T *array, size_t length, void (*f)(T arg)) {
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif
