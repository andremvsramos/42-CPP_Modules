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
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"

int	main()
{
	std::srand(std::time(NULL));
	Bureaucrat Ivone("Ivone", 100);
	ShrubberyCreationForm	SCF("garden.txt");
	RobotomyRequestForm		RRF(Ivone.getName());
	PresidentialPardonForm	PPF(Ivone.getName());

	SCF.beSigned(Ivone);
	try {
		Ivone.signForm(SCF);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Ivone.executeForm(SCF);

	try {
		Ivone.signForm(RRF);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Ivone.executeForm(RRF);

	try {
		Ivone.signForm(PPF);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Ivone.executeForm(PPF);

	return (0);
}
