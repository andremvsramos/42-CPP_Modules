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

#include "../headers/Serializer.hpp"

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

int	main()
{
	Data	*data = new Data;
	data->secretMessage = readInput("Enter a secret message: ");
	data->hiddenChars = data->secretMessage.length();
	uintptr_t zip = Serializer::serialize(data);
	std::cout << "Original data: " << data->secretMessage << std::endl;
	std::cout << "Original data: " << data->hiddenChars << std::endl;
	std::cout << "Serialized data: " << zip << std::endl;
	data = Serializer::deserialize(zip);
	std::cout << "Deserialized data: " << data->secretMessage << std::endl;
	std::cout << "Deserialized data: " << data->hiddenChars << std::endl;
	delete data;
	return (0);
}
