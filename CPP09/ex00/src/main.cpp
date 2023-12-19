/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:06:55 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/19 20:06:55 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"

int	main() {

	BitcoinExchange	btc;

	try {
		btc.dbConversion();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
