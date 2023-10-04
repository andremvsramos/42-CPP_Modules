/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:57:05 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 14:57:05 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Zombie.hpp"

int	main(void)
{
	int	size;
	std::string	zombieName;
	Zombie *horde;

	std::cout << "Please input a horde size: ";
	std::cin >> size;
	if (std::cin.fail())
		return (std::cout << "Please only input integers as a size\n", 1);
	std::cout << "Please input a name for all zombies: ";
	std::cin >> zombieName;
	horde = zombieHorde(size, zombieName);
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
