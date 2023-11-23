/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:25:02 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/13 12:34:43 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& original);
        ScavTrap&    operator=(const ScavTrap& original);
        ~ScavTrap();
        void        setScavHP(int amount);
        void        setScavMP(int amount);
        int         getScavHP();
        int         getScavMP();
        int         getScavATK();
        std::string getScavName();
        void        guardGate();
        void        scavAttack(const std::string& target);
        void        scavTakeDmg(unsigned int amount);
};

#endif
