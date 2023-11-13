/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:42:52 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/18 15:28:40 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Harl.hpp"

int	main(int ac, char **av)
{
	Harl	Harl;

	switch (ac)
	{
		case 2:
			Harl.complain(av[1]);
			break;

		default:
			Harl.complain("");
			break;
	}
	return (0);
}
