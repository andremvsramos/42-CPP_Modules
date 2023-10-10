/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:57:35 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/10 12:16:18 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ClapTrap.hpp"
#include <cmath>
#include <ctime>
#include <cstdlib>

int	main(void)
{
	ClapTrap	CP("Johnny Boy");
	int			targetHP = 10;
	int			dmgTaken;
	std::srand(std::time(NULL));

	while (CP.getHP() && targetHP)
	{
		dmgTaken = rand() % 3;
		CP.setATK(dmgTaken);
		targetHP -= dmgTaken;
		if (targetHP <= 0)
		{
			targetHP = 0;
			std::cout << "\n----Target has died!----\n";
			break ;
		}
		std::cout << "\n";
		CP.attack("Ezio Auditore");
		std::cout << "\nTarget has " << targetHP << " HP left!\n";
		std::cout << "\n";
		CP.takeDamage(rand() % 5);
		if (CP.getHP() <= 0)
			break ;
		std::cout << "\n";
		CP.beRepaired(rand() % 3);
		std::cout << "\n";
	}
	return (0);
}
