/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:52:35 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 14:52:35 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Character.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &original) {
	this->_name = original._name;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = original._inventory[i]->clone();
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i]) {
			std::cout << "enter" << std::endl;
			delete this->_inventory[i];
		}
}

Character &Character::operator=(Character const &original) {
	if (this != &original)
	{
		this->_name = original._name;
		for (int i = 0; i < 4; i++)
			if (this->_inventory[i])
				delete this->_inventory[i];
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = original._inventory[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			std::cout << "Equipped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full. Could not equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "Unequipped " << this->_inventory[idx]->getType() << std::endl;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] && this->_inventory[idx]->getType() != "")
		this->_inventory[idx]->use(target);
	else
		std::cout << "Empty materia slot" << std::endl;
}
