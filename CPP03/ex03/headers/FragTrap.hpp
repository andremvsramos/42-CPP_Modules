/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:50:02 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/30 11:15:25 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{

    private:

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& original);
        FragTrap&    operator=(const FragTrap& original);
        ~FragTrap();
        void        setFragHP(int amount);
        void        setFragMP(int amount);
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
