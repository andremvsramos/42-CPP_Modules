/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:43:14 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 11:43:14 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(WrongCat const &original) : WrongAnimal(original) {
	std::cout << "WrongCat copy constructor called\n";
	*this = original;
}

WrongCat &WrongCat::operator=(WrongCat const &original) {
	std::cout << "WrongCat assignation operator called\n";
	if (this != &original)
		this->setType(original.getType());
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Rawr Rawr\n";
}
