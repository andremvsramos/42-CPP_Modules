/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:37:33 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/04 15:37:33 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main(void)
{
	std::string	brain("HI THIS IS BRAIN");
	std::string *stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << &brain << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";

	std::cout << brain << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";

	return (0);
}
