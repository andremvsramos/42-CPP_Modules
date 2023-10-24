/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:00:19 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 11:00:19 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called\n";
}

Dog::~Dog() {
	std::cout << "Dog destructor called\n";
}

Dog::Dog(Dog const &original) : Animal(original) {
	std::cout << "Dog copy constructor called\n";
	*this = original;
}

Dog &Dog::operator=(Dog const &original) {
	std::cout << "Dog assignation operator called\n";
	if (this != &original)
		this->setType(original.getType());
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Woof woof\n";
}
