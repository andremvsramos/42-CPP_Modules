/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:05:06 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 11:05:06 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"
#include "../headers/Brain.hpp"
#include <cstdlib>
#include <ctime>

int main() {

	// Animal	animal;	compilation error

	{
		Cat	cat;
		cat.makeSound();
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Animal	*animal = new Dog();
	animal->makeSound();
	delete animal;
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}

