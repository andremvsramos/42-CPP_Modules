/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:57:35 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/18 09:56:24 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScavTrap.hpp"
#include <cmath>
#include <ctime>
#include <cstdlib>

int	main(void)
{
	ScavTrap	ST("50 Cent");
	ClapTrap	CT("Johnny Boy");
	std::srand(std::time(NULL));

	while (CT.getHP() && ST.getScavHP())
	{
		CT.setATK(rand() % 30);
		if (ST.getScavHP() <= 0)
		{
			ST.setScavHP(0);
			std::cout << "\n---" << ST.getScavName() << " has died!----\n";
			break ;
		}
		std::cout << "\n";
		CT.attack(ST.getScavName());
		if (ST.getScavHP() <= 0)
		{
			ST.setScavHP(0);
			std::cout << "\n---" << ST.getScavName() << " has died!----\n";
			break ;
		}
		ST.scavTakeDmg(CT.getATK());
		std::cout << "\n" << ST.getScavName() << " has " << ST.getScavHP() << " HP left!\n";
		std::cout << "\n";
		ST.scavAttack(CT.getName());
		CT.takeDamage(ST.getScavATK());
		if (CT.getHP() <= 0)
			break ;
		std::cout << "\n";
		CT.beRepaired(rand() % 10);
		std::cout << "\n";
	}
	return (0);
}
