/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:47:26 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/06 09:47:26 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/Intern.hpp"

int	main()
{
	std::srand(std::time(NULL));
	Intern	a;
	AForm *newForm;

	try {
		newForm = a.makeForm("ShrubberyCreationForm", "garden.txt");
		std::cout << "Form Created: " << newForm->getName() << std::endl;
		delete newForm;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	try {
		newForm = a.makeForm("RobotomyRequestForm", "50 Cent");
		std::cout << "Form Created: " << newForm->getName() << std::endl;
		delete newForm;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		newForm = a.makeForm("PresidentialPardonForm", "Homer");
		std::cout << "Form Created: " << newForm->getName() << std::endl;
		delete newForm;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\t\n===TESTING ERROR===\t\n" << std::endl;
	try {
		newForm = a.makeForm("ErrorForm", "NULL");
		std::cout << "Form Created: " << newForm->getName() << std::endl;
		delete newForm;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
