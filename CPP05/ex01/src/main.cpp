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
#include "../headers/Form.hpp"

int	main()
{
	Bureaucrat Ivone("Ivone", 100);
	std::cout << Ivone << std::endl;

	std::cout << "\t\n===TESTING EX01===\t\n" << std::endl;


	Ivone.setGrade(120);
	std::cout << Ivone << std::endl;
	Form form1("Form_28B", 100, 75);
	Form form2("Form_28C", 130, 50);
	Form form3(form1);
	Form form4 = form2;

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << form4 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Test exceptions" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try{
		Form form5("Form_28D", 0, 50);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Form form6("Form_28E", 151, 50);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Form form7("Form_28F", 100, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Form form8("Form_28G", 100, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Test Sign Forms" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try{
		form1.beSigned(Ivone);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	form2.beSigned(Ivone);
	form2.beSigned(Ivone);

	std::cout << std::endl;

	try{
		Ivone.signForm(form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
