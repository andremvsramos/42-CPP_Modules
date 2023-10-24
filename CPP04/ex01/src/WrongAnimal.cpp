/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:40:38 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 11:40:38 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("empty") {
	std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "WrongAnimal constructor called\n";
	this->setType(type);
}

WrongAnimal::~WrongAnimal() {
	if (this->getType() != "empty")
		std::cout << "Empty WrongAnimal destructor called\n";
	else
		std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &original) {
	std::cout << "WrongAnimal copy constructor called\n";
	*this = original;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &original) {
	std::cout << "WrongAnimal assignation operator called\n";
	if (this != &original)
		this->setType(original.getType());
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound\n";
}

void	WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}
