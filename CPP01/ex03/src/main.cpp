/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:34:09 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 16:34:09 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/HumanA.hpp"
#include "../headers/HumanB.hpp"

int	main(void)
{
	Weapon	club = Weapon("club");

	HumanA	Bob("Bob", club);
	Bob.attack();
	club.setType("sword");
	Bob.attack();

	Weapon stick = Weapon("stick");

	HumanB	Jack("Jack");
	Jack.attack();
	Jack.setWeapon(&stick);
	Jack.attack();
}
