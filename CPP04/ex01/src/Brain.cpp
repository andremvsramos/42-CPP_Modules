/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:54:57 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 11:54:57 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Brain.hpp"
#include <cstdlib>
#include <ctime>

Brain::Brain() {
	std::cout << "\tBrain constructor called\n";
	const std::string possible_ideas[] = {
		"bark",
		"poop",
		"pee",
		"eat",
		"roll over",
		"play dead",
		"fetch",
		"lick",
		"scrath",
		"puke",
	};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = possible_ideas[rand() % 10];
	std::cout << "Printing 5 random ideas:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "\t\t" << this->_ideas[i] << std::endl;
}

Brain::~Brain() {
	std::cout << "\tBrain destructor called\n";
}

Brain::Brain(Brain const &original) {
	std::cout << "Brain copy constructor called\n";
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = original._ideas[i];
}

Brain &Brain::operator=(Brain const &original) {
	std::cout << "Brain assignation operator called\n";
	if (this != &original)
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = original._ideas[i];
	return (*this);
}
