/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:41:56 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/31 07:45:06 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
    ClapTrap("default_clap_name") , FragTrap(), ScavTrap(), _name("default") {
        this->setHP(FragTrap::getFragHP());
        this->setMP(ScavTrap::getScavMP());
        this->setATK(FragTrap::getATK());
        std::cout << "\t\n===DiamondTrap " << _name << " created!===\n";
        std::cout << "\t HP: " << getHP() << "\n";
        std::cout << "\t MP: " << getMP() << "\n";
        std::cout << "\t ATK: " << getATK() << "\n";
        std::cout << "===ClapTrap " << ClapTrap::getName() << " created!===\n\n";
    }

DiamondTrap::DiamondTrap(const std::string& name) :
    ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
        this->setHP(FragTrap::getFragHP());
        this->setMP(ScavTrap::getScavMP());
        this->setATK(FragTrap::getATK());
        std::cout << "\t\n===DiamondTrap " << _name << " created!===\n";
        std::cout << "\t HP: " << getHP() << "\n";
        std::cout << "\t MP: " << getMP() << "\n";
        std::cout << "\t ATK: " << getATK() << "\n";
        std::cout << "===ClapTrap " << ClapTrap::getName() << " created!===\n\n";
}

DiamondTrap::DiamondTrap (const DiamondTrap& original) {
    std::cout << "Copy of DiamondTrap " << _name << " created!\n";
    _name = original.getName();
    this->setHP(original.getHP());
    this->setMP(original.getMP());
    this->setATK(original.getATK());
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& original) {
    std::cout << "Copy assignment of DiamondTrap " << _name << " created!\n";
    if (this != &original) {
        _name = original.getName();
        this->setHP(original.getHP());
        this->setMP(original.getMP());
        this->setATK(original.getATK());
    }
    return (*this);
}

DiamondTrap::~DiamondTrap () {
    std::cout << "DiamondTrap " << _name << " was destroyed!\n";
}

void    DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << getName() << "\n";
    std::cout << "ClapTrap name: " << ClapTrap::getName() << "\n";
}

int     DiamondTrap::getD_HP() {
    return (getHP());
}

int     DiamondTrap::getD_MP() {
    return (getMP());
}

int     DiamondTrap::getD_ATK() {
    return (getATK());
}
