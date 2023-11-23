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
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
		this->_floor[i] = NULL;
	}
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
		this->_floor[i] = NULL;
	}
}

Character::Character(Character const &original) {
	this->_name = original._name;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (this->_floor[i])
			delete this->_floor[i];
		this->_inventory[i] = original._inventory[i]->clone();
		this->_floor[i] = original._floor[i]->clone();
	}
}

Character::~Character() {
	for (int i = 0; i < 1; i++) {
		if (this->_inventory[i]) {
			std::cout << this->_inventory[i]->getType() << std::endl;
			delete this->_inventory[i];
		}
		if (this->_floor[i]) {
			std::cout << this->_floor[i]->getType() << std::endl;
			delete this->_floor[i];
		}
	}
}

Character &Character::operator=(Character const &original) {
	if (this != &original)
	{
		this->_name = original._name;
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (this->_floor[i])
				delete this->_floor[i];
			this->_inventory[i] = original._inventory[i]->clone();
			this->_floor[i] = original._floor[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << m->getType() << " Equipped" << std::endl;
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
	if (!this->_inventory[idx])
	{
		std::cout << "Slot is empty" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_floor[i] == NULL) {
			this->_floor[i] = this->_inventory[idx];
			std::cout << this->_floor[i]->getType() << std::endl;
			this->_inventory[idx] = NULL;
			std::cout << "Unequipped " << this->_floor[i]->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Floor is already cluttered! Best not throw more trash! Couldn't unequip " << this->_inventory[idx]->getType() << std::endl;
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
