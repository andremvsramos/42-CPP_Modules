/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:59:32 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 15:59:32 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.h"

class HumanA
{
	private:
		Weapon		*_weapon;
		std::string	_name;

	public:
		HumanA(std::string name, Weapon *weapon);
		~HumanA();
		void	attack();

};

#endif
