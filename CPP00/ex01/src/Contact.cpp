/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:59:11 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 15:59:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Contact.hpp"

std::string	Contact::getFirstName()
{
	return (FirstName);
}

std::string	Contact::getLastName()
{
	return (LastName);
}

std::string	Contact::getNickName()
{
	return (NickName);
}

std::string	Contact::getPhoneNumber()
{
	return (PhoneNumber);
}

std::string	Contact::getDarksecret()
{
	return (DarkSecret);
}

void	Contact::getInfo()
{
	std::cout << std::setw(15) << "First name: " << getFirstName() << "\n";
	std::cout << std::setw(15) << "Last name: " << getLastName() << "\n";
	std::cout << std::setw(15) << "Nick name: " << getNickName() << "\n";
	std::cout << std::setw(15) << "Phone Number: " << getPhoneNumber() << "\n";
	std::cout << std::setw(15) << "Darkest Secret: " << getDarksecret() << "\n";
}

void	Contact::setInfo()
{
	FirstName = readInput("First Name: ");
	LastName = readInput("Last Name: ");
	NickName = readInput("Nick Name: ");
	PhoneNumber = readInput("Phone Number: ");
	DarkSecret = readInput("Darkest Secret: ");
}
