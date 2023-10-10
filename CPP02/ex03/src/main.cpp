/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:08 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/10 09:44:57 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/bsp.hpp"

int main( void ) {
	Point const a(-2, 5);
	Point const b(1, 3);
	Point const c(4, 4);
	Point const dot(-1, 4.5);

	if(bsp( a, b, c, dot))
		std::cout << "Its in there!" << std::endl;
	else
		std::cout << "Its outside of the triangle!" << std::endl;
	return 0;
}
