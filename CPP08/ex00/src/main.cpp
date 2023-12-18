/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:47:26 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/06 09:47:26 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/easyfind.hpp"

int main( void ) {

	std::vector<int> values;

	for (size_t i = 0; i < 5; i++)
		values.push_back(i + 1);

	easyfind(values, 5);
	try{
		easyfind(values, 6);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
