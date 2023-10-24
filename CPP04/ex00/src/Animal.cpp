/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:50:05 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 10:50:05 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Animal.hpp"

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal constructor called\n";
}

Animal::Animal() : type("empty") {
	std::cout << "Default Animal constructor called\n";
}

Animal::~Animal() {
	if (this->getType() != "empty")
		std::cout << "Empty Animal destructor called\n";
	else
		std::cout << "Animal destructor called\n";
}

Animal::Animal(Animal const &original) {
	std::cout << "Animal copy constructor called\n";
	*this = original;
}

Animal &Animal::operator=(Animal const &original) {
	std::cout << "Animal assignation operator called\n";
	if (this != &original)
		this->setType(original.getType());
	return (*this);
}

void	Animal::setType(std::string type) {
	this->type = type;
}

std::string	Animal::getType() const {
	return (this->type);
}

void	Animal::makeSound() const {
	std::cout << "Animal sound\n";
}
