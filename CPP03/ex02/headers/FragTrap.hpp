/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:50:02 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/18 17:55:51 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : ClapTrap
{

    private:

    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& original);
        FragTrap&    operator=(const FragTrap& original);
        ~FragTrap();
        void        setFragHP(unsigned int amount);
        void        setFragMP(unsigned int amount);
        int         getFragHP();
        int         getFragMP();
        int         getFragATK();
        std::string getFragName();
        void        guardGate();
        void        fragAttack(const std::string& target);
        void        fragTakeDmg(unsigned int amount);
        void        highFivesGuys(void);
};

#endif
