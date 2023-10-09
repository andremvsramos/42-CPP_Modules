/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:42:50 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 14:24:56 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "\n[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "\n[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "\n[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "\n[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	int	n = -1;

	void (Harl::*levelFunctions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string	type[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
		if (level == type[i])
			n = i;

	switch (n)
	{
		case 0:
			for (int i = n; i < 4; i++)
				(this->*levelFunctions[i])();
			break;

		case 1:
			for (int i = n; i < 4; i++)
				(this->*levelFunctions[i])();
			break;

		case 2:
			for (int i = n; i < 4; i++)
				(this->*levelFunctions[i])();
			break;

		case 3:
			(this->*levelFunctions[3])();
			break;

		default:
			break;
	}


}
