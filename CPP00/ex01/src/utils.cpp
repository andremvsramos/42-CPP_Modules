/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:04:37 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 17:04:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PhoneBook.hpp"

std::string	readInput(std::string str)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Error: getline\n";
			exit (1);
		}
	}
	return (input);
}

std::string	formatString(std::string str)
{
	if (str.size() <= 9)
		return (str);
	else
	{
		std::string format = str.substr(0, 9).append(".");
		return (format);
	}
}

bool	is_num(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}
