/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:42:52 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 14:00:22 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Harl.hpp"

static	std::string	readInput(std::string str)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			std::cout << "EXIT\n";
			exit (0);
		}
	}
	return (input);
}

int	main(void)
{
	Harl		Harl;
	std::string	input;

	while (true)
	{
		std::cout << "Available commands: DEBUG | INFO | WARNING | ERROR\n";
		input = readInput("Please input a command: ");
		Harl.complain(input);
		std::cout << "\n";
	}
	return (0);
}
