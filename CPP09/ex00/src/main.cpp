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

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string		input(av[1]);
	BitcoinExchange	btc(input);
	btc.doExchange();
	return (EXIT_SUCCESS);
}
