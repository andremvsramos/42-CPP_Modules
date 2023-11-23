/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:14:23 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/13 12:33:07 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ClapTrap.hpp"

ClapTrap::ClapTrap () :
    _name("Default"), _hp(100), _mp(20), _atk(0) {
        std::cout << "---Default ClapTrap has been created---\n";
}

ClapTrap::ClapTrap (std::string name) :
    _name(name), _hp(100), _mp(20), _atk(0) {
        std::cout << "---ClapTrap " << getName() << " has been created---\n";
}

ClapTrap::ClapTrap (const ClapTrap& original) {
    std::cout << "Copy constructor has been called\n";
    _name = original.getName();
    _hp = original.getHP();
    _mp = original.getMP();
    _atk = original.getATK();
}

ClapTrap &ClapTrap::operator=(const ClapTrap& original) {
    std::cout << "Copy assignment operator has been called\n";
    if (this == &original)
        return (*this);
    _name = original.getName();
    _hp = original.getHP();
    _mp = original.getMP();
    _atk = original.getATK();
    return (*this);
}

ClapTrap::~ClapTrap () {
    if (getHP() > 0)
        std::cout << "\n---ClapTrap " << getName() << " was victorious!---\n";
    else std::cout << "\n---ClapTrap " << getName() << " has been destroyed---\n";
}

void ClapTrap::attack(const std::string& target) {
    if (getMP() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " has no energy left!\n";
        return ;
    }
    std::cout << "ClapTrap " << getName()
        << " attacks, causing " << getATK()
        << " points of damage to " << target << "!\n";
    _mp--;
    std::cout << "ClapTrap " << getName() << " currently has "
        << getMP() << " energy left!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << getName() << " has taken "
        << amount << " points of damage!\n";
    if (getHP() > 0)
        _hp -= amount;
    if (getHP() < 0)
        _hp = 0;
    std::cout << "ClapTrap " << getName() << " currently has "
        << getHP() << " HP left!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (getMP() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " has no energy left!\n";
        return ;
    }
    std::cout << "ClapTrap " << getName()
        << " has repaired itself, restoring "
        << amount << " points of HP!\n";
    _hp += amount;
    _mp--;
    std::cout << "ClapTrap " << getName() << " currently has "
        << getMP() << " energy left and has " << getHP() << " HP!\n";
}

std::string ClapTrap::getName() const {
    return (_name);
}

int ClapTrap::getHP() const {
    return (_hp);
}

int ClapTrap::getMP() const {
    return (_mp);
}

int ClapTrap::getATK() const {
    return (_atk);
}

void ClapTrap::setHP(unsigned int amount) {
    _hp = amount;
}

void ClapTrap::setMP(unsigned int amount) {
    _mp = amount;
}

void ClapTrap::setATK(unsigned int amount) {
    _atk = amount;
}

void ClapTrap::setName(std::string name) {
    _name = name;
}
