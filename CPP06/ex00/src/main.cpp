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

int	main()
{
	Bureaucrat test;
	Bureaucrat Ze("Ze", 150);
	Bureaucrat Carlos(Ze);
	Bureaucrat Ivone("Ivone", 100);

	std::cout << test << std::endl;
	std::cout << Ze << std::endl;
	std::cout << Carlos << std::endl;
	std::cout << Ivone << std::endl;
	std::cout << std::endl;

	test = Bureaucrat("Test", 120);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Test exceptions" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try {
		Bureaucrat TooLow("TooLow", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	try {
		Bureaucrat TooHigh("TooHigh", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << Ze << std::endl;

	try {
		Ze.decrementGrade(1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	Carlos.setGrade(1);
	std::cout << "ZeCarlos: " << Carlos << std::endl;
	try {
		Carlos.incrementGrade(1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Testing Increments and Decrements" << std::endl;
	std::cout << std::endl;

	Ze.setGrade(100);
	Carlos.setGrade(100);
	Ivone.setGrade(100);

	std::cout << Ze << std::endl;
	std::cout << Carlos << std::endl;
	std::cout << Ivone << std::endl;

	std::cout << std::endl;
	Ze.incrementGrade(10);
	Carlos.decrementGrade(10);
	Ivone.incrementGrade(25);
	std::cout << Ze << std::endl;
	std::cout << Carlos << std::endl;
	std::cout << Ivone << std::endl;
	return (0);
}
