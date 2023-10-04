/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:54:04 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 16:54:04 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/HumanB.hpp"

HumanB::HumanB(std::string name) :
	_weapon(0), _name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " has no weapon\n";
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}
