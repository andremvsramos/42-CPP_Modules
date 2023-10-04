/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:15:44 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 16:15:44 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.h"

class HumanB
{
	private:
		Weapon		*_weapon;
		std::string	_name;

	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon *weapon);

};

#endif
