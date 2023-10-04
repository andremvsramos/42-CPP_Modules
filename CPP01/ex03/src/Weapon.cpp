/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:29:21 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 16:29:21 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Weapon.h"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon()
{
	std::cout << _type << " has been discarded\n";
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

std::string	&Weapon::getType()
{
	return (_type);
}
