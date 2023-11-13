/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:57:35 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/30 09:29:03 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScavTrap.hpp"
#include "../headers/FragTrap.hpp"
#include <cmath>
#include <ctime>
#include <cstdlib>

int	checkScavHP(ScavTrap& ST)
{
	if (ST.getScavHP() <= 0)
	{
		ST.setScavHP(0);
		std::cout << "\n---" << ST.getScavName() << " has died!----\n";
		return 1;
	}
	return 0;
}

int	main(void)
{
	ScavTrap	ST("50 Cent");
	ClapTrap	CT("Johnny Boy");
	FragTrap	FT("Chopin");
	std::srand(std::time(NULL));
	int			target;
	std::string	TargetTrap;

	FT.highFivesGuys();
	while (CT.getHP() && ST.getScavHP())
	{
		target = rand() % 1;
		if (target)
		{
			FT.fragAttack(ST.getScavName());
			if (checkScavHP(ST))
				break ;
		}
		else
		{
			FT.fragAttack(CT.getName());
			if (CT.getHP() <= 0)
				break ;
		}
		CT.setATK(rand() % 30);
		if (checkScavHP(ST))
			break ;
		std::cout << "\n";
		CT.attack(ST.getScavName());
		if (checkScavHP(ST))
			break ;
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
