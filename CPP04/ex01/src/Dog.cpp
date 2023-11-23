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
	_brain = new Brain(*original._brain);
	// _brain = original._brain; Shallow copy example
}

Dog &Dog::operator=(Dog const &original) {
	std::cout << "Dog assignation operator called\n";
	if (this != &original) {
		this->setType(original.getType());
		_brain = new Brain(*original._brain);
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Woof woof\n";
}

void	Dog::getBrain() const {
	std::cout << "Dog Brain is: " << _brain << std::endl;
}
