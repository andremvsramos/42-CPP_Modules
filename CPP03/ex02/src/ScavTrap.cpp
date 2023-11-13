/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:29:26 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/16 11:28:54 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScavTrap.hpp"

ScavTrap::ScavTrap (std::string name) : ClapTrap(name) {
    this->setHP(100);
    this->setMP(50);
    this->setATK(20);
    std::cout << "---ScavTrap " << this->getName() << " has been created---\n";
}

ScavTrap::ScavTrap (const ScavTrap& original) : ClapTrap(original) {
    std::cout << "Copy constructor has been called\n";
    setName(original.getName());
    setHP(original.getHP());
    setMP(original.getMP());
    setATK(original.getATK());
}

ScavTrap &ScavTrap::operator=(const ScavTrap& original) {
    std::cout << "Copy assignment operator has been called\n";
    if (this == &original)
        return (*this);
    ClapTrap::operator=(original);
    setName(original.getName());
    setHP(original.getHP());
    setMP(original.getMP());
    setATK(original.getATK());
    return (*this);
}

ScavTrap::~ScavTrap () {
    if (getHP() > 0)
        std::cout << "\n---ScavTrap " << getName() << " was victorious!---\n";
    else std::cout << "\n---ScavTrap " << getName() << " has been destroyed---\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode\n";
}

void ScavTrap::setScavHP(unsigned int amount) {
    setHP(amount);
}

void ScavTrap::setScavMP(unsigned int amount) {
    setMP(amount);
}

int ScavTrap::getScavHP() {
    return (getHP());
}

int ScavTrap::getScavMP() {
    return (getMP());
}

int ScavTrap::getScavATK() {
    return (getATK());
}

std::string ScavTrap::getScavName() {
    return (getName());
}

void ScavTrap::scavAttack(const std::string& target) {
    std::cout << "-------HOL' UP!-------\n\n";
    std::cout << getName() << " IS ATTACKING!\n";
    attack(target);
    std::cout << "\n----------------------\n\n";
}

void ScavTrap::scavTakeDmg(unsigned int amount) {
    takeDamage(amount);
}
