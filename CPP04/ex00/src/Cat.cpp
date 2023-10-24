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
}

Cat::~Cat() {
	std::cout << "Cat destructor called\n";
}

Cat::Cat(Cat const &original) : Animal(original) {
	std::cout << "Cat copy constructor called\n";
	*this = original;
}

Cat &Cat::operator=(Cat const &original) {
	std::cout << "Cat assignation operator called\n";
	if (this != &original)
		this->setType(original.getType());
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow meow\n";
}
