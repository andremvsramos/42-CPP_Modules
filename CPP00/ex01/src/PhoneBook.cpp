/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:16:09 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 17:16:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0), index(0) {}

void	PhoneBook::addContact()
{
	std::cout << "\n----New Contact----\n";
	c[index].setInfo();
	std::cout << "\n---Contact added---\n";
	index++;
	size++;
	if (index == 8)
		index = 0;
}

void	PhoneBook::searchContact()
{
	int			num;
	std::string	input;

	if (size == 0)
	{
		std::cout << "No contacts in phonebook\n";
		return ;
	}
	while (1)
	{
		displaySearch(10);
		input = readInput("Please enter the index of the contact to search: ");
		num = std::atoi(input.c_str());
		if (input == "EXIT")
			break ;
		if (input.empty() || (num < 0 || num > size - 1) || !is_num(input))
		{
			std::cout << input << " is not a valid input, please try again\n";
			continue ;
		}
		else
		{
			std::cout << "\n----Contact Info----\n\n";
			getContact(num).getInfo();
			std::cout << "\n--------------------\n\n";
		}
	}
}

void	PhoneBook::displaySearch(int spacing)
{
	std::cout << "\n----Contact List----\n\n";
	std::cout << std::setw(spacing) << "     INDEX|" ;
	std::cout << std::setw(spacing) << "      NAME|";
	std::cout << std::setw(spacing) << " LAST NAME|";
	std::cout << std::setw(spacing) << " NICK NAME|";
	std::cout << "\n";
	for (int i = 0; (i < size && i < 8); i++)
	{
		std::cout << std::setw(spacing) << i << "|";
		std::cout << std::setw(spacing) << formatString(getContact(i).getFirstName()) << "|";
		std::cout << std::setw(spacing) << formatString(getContact(i).getLastName()) << "|";
		std::cout << std::setw(spacing) << formatString(getContact(i).getNickName()) << "|";
		std::cout << "\n";
	}
	std::cout << "\n--------------------\n";
}

Contact	PhoneBook::getContact(int index)
{
	return (c[index]);
}
