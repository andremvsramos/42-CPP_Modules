/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:25:02 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/13 12:31:15 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& original);
        ScavTrap&    operator=(const ScavTrap& original);
        ~ScavTrap();
        void        setScavHP(unsigned int amount);
        void        setScavMP(unsigned int amount);
        int         getScavHP();
        int         getScavMP();
        int         getScavATK();
        std::string getScavName();
        void        guardGate();
        void        scavAttack(const std::string& target);
        void        scavTakeDmg(unsigned int amount);
};

#endif
