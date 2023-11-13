/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:42:01 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/30 11:29:17 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# pragma once

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap
{

    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& original);
        DiamondTrap&    operator=(const DiamondTrap& original);
        ~DiamondTrap();
        void    whoAmI();
        int     getD_HP();
        int     getD_MP();
        int     getD_ATK();
        using   ScavTrap::attack;
};

#endif
