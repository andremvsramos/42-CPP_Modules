/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:47:26 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/06 09:47:26 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Base.hpp"
#include <unistd.h>

int	main()
{
	std::srand(std::time(NULL));
	Base *base = generate();
	std::cout << "Identify by pointer: ";
		identify(base);
	std::cout << "Identify by reference: ";
		identify(*base);
	delete base;
	sleep(1);
	base = generate();
	std::cout << "Identify by pointer: ";
		identify(base);
	std::cout << "Identify by reference: ";
		identify(*base);
	delete base;
	sleep(1);
	base = generate();
	std::cout << "Identify by pointer: ";
		identify(base);
	std::cout << "Identify by reference: ";
		identify(*base);
	delete base;
	return (0);
}
