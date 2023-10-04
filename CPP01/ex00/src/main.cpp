/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:41:07 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 14:41:07 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (std::cout << "Please type at least one name\n", 1);
	for (int i = 1; av[i]; i++)
	{
		std::string	zombieName(av[i]);
		std::cout << "This zombie was developed in Stack™\n";
		randomChump(zombieName);
		std::cout << "\nAnd this zombie was developed by Heap©\n";
		Zombie *ptrZombie = newZombie(zombieName);
		ptrZombie->announce();
		delete (ptrZombie);
	}
	return (0);
}
