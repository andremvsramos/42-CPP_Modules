/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:15:43 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 15:15:43 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.hpp"

int main() {

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n\t=== Testing full materia source ===\n" << std::endl;

		std::cout << "Should print \"MateriaSource is full\"" << std::endl;
			src->learnMateria(new Ice());

	std::cout << "\n\t=== Testing inventory ===\n" << std::endl;

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);

	std::cout << "\n\t=== Testing full inventory ===\n" << std::endl;

		std::cout << "Should print \"Inventory is full\"" << std::endl;
			me->equip(tmp);



	std::cout << "\n\t=== Testing valid indexes ===\n" << std::endl;

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);


	std::cout << "\n\t=== Testing invalid indexes ===\n" << std::endl;

		std::cout << "= Testing uniquiping && using =\n" << std::endl;

			me->unequip(3);
			me->use(3, *bob);
			me->equip(tmp);
			me->use(3, *bob);
			std::cout << std::endl;

		std::cout << "Should print \"Invalid index\" twice" << std::endl;
			me->use(4, *bob);
			me->use(-1, *bob);
			std::cout << std::endl;

	delete bob;
	std::cout << "bob deleted" << std::endl;
	delete tmp;
	std::cout << "tmp deleted" << std::endl;
	delete me;
	std::cout << "me deleted" << std::endl;
	delete src;
	std::cout << "src deleted" << std::endl;

	return 0;
}
