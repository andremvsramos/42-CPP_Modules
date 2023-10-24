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
	std::cout << "--> Calling new on dog _brain\n";
		_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "\nDog destructor called\n";
	std::cout << "--> Calling delete on dog _brain\n";
		delete _brain;
}

Dog::Dog(Dog const &original) : Animal(original) {
	std::cout << "Dog copy constructor called\n";
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

Dog	*Dog::clone() const {
	Dog	*dog = new Dog(*this);
	dog->_brain = new Brain(*this->_brain);
	return (dog);
}
