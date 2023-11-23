/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:03:38 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 11:03:38 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called\n";
	std::cout << "--> Calling new on cat _brain\n";
		_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "\nCat destructor called\n";
	std::cout << "--> Calling delete on cat _brain\n";
		delete _brain;
}

Cat::Cat(Cat const &original) : Animal(original) {
	std::cout << "Cat copy constructor called\n";
	_brain = new Brain(*original._brain);
}

Cat &Cat::operator=(Cat const &original) {
	std::cout << "Cat assignation operator called\n";
	if (this != &original) {
		this->setType(original.getType());
		_brain = new Brain(*original._brain);
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow meow\n";
}
