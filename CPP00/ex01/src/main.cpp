/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:05:42 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 17:05:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	pb;

	while (1)
	{
		std::cout << "\nAvailable commands are: ADD | SEARCH | EXIT\n";
		input = readInput("Please enter a command: ");
		if (input == "EXIT")
		{
			std::cout << "Exiting.\n";
			break ;
		}
		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.searchContact();
		else
			std::cout << "Error: Invalid command, please try again\n";
	}
	return (0);
}
