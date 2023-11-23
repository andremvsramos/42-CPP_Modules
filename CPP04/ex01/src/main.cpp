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
#include <cstdlib>

int main() {


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

		std::cout << "\n\t=== Deleting Animal Array ===\n" << std::endl;

		for (int i = 0; i < n; i++)
			delete animals[i];

		std::cout << "\t\n===CHECKING COPY===\t\n" << std::endl;

		Dog	*dog = new Dog();
		Dog	*dog_cpy = new Dog(*dog);

		std::cout << "\nDog address: " << dog << std::endl;
		dog->getBrain();
		delete dog;

		std::cout << "\nDog_Cpy address: " << dog_cpy << std::endl;
		dog_cpy->getBrain();
		delete dog_cpy;

		std::cout << "\t\n===COPY CHECK END===\t\n" << std::endl;



	return (0);
}

