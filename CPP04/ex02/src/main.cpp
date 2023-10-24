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

	std::srand(std::time(NULL));
	std::cout << "\n\t=== Testing Animal ===\n" << std::endl;

		//const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		//meta->makeSound();

		//delete meta;
		delete j;
		delete i;


	std::cout << "\n\t=== Testing wrong inheritance ===\n" << std::endl;

		//const WrongAnimal *wmeta = new WrongAnimal();
		const WrongAnimal *wcat = new WrongCat();

		wcat->makeSound();
		//wmeta->makeSound();

		delete wcat;
		//delete wmeta;

	std::cout << "\n\t=== Testing Animal Array ===\n" << std::endl;

		std::cout << "=== Please input an array number: ";
		std::string	input;

		if (!std::getline(std::cin, input)) {
			std::cout << "Error reading input" << std::endl;
			return (1);
		}
		int n = std::atoi(input.c_str());
		Animal *animals[n];
		for (int i = 0; i < n; i++) {
			if (i < n / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << "\n\t=== Testing Array makeSound() ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			animals[i]->makeSound();
		}

		std::cout << "\n\t=== Deleting Animal Array ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			delete animals[i];
		}

	std::cout << "\n\t=== Testing Deep Copy Constructor Array===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			if (i < n / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << "\n\t=== Copying Animal Array ===\n" << std::endl;

		Animal *animals2[n];
		for (int i = 0; i < n; i++) {
			animals2[i] = animals[i]->clone();
		}

		std::cout << "\n\t=== Testing Deep Copy makeSound() ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			animals2[i]->makeSound();
		}


		std::cout << "\n\t=== Deleting Animal Array ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			delete animals[i];
		}

		std::cout << "\n\t=== Deleting Copied Animal Array ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			delete animals2[i];
		}


	std::cout << "\n\t=== Testing Shallow Copy Constructor Array===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			if (i < n / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << "\n\t=== Copying Animal Array ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			animals2[i] = animals[i];
		}

		std::cout << "\n\t=== Testing Shallow Copy makeSound() ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			animals2[i]->makeSound();
		}

		std::cout << "\n\t=== Deleting Copied Animal Array ===\n" << std::endl;

		for (int i = 0; i < n; i++) {
			delete animals2[i];
		}

	return (0);
}

