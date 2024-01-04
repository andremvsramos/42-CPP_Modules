/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:47:52 by andvieir          #+#    #+#             */
/*   Updated: 2024/01/04 15:47:52 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "\033[1;31mERROR: Input must be as follows ->"
			<< "./PmergeMe \033[4m<list_of_numbers>\033[0m !"
			<< "\nPlease, try again.\033[0m" << std::endl;
		return (EXIT_FAILURE);
	}
	for (int i = 1; i < ac; i++) {
		std::string str(av[i]);
		for (size_t j = 0; j < str.length(); j++) {
			if (!isdigit(str[j])) {
				std::cout << "\033[1;31mERROR: "
				<< "Input arguments must contain only positive numbers!\033[0m"
				<< std::endl;
				return (EXIT_FAILURE);
			}
		}
	}
	std::vector<int> stack;
	for (int i = 1; i < ac; i++) {
		if (atol(av[i]) < INT_MIN || atol(av[i]) > INT_MAX) {
			std::cout << "\033[1;31mERROR: "
				<< "Input arguments must be contained within integer limits!\033[0m"
				<< std::endl;
				return (EXIT_FAILURE);
		}
		else stack.push_back(atoi(av[i]));
	}
	PmergeMe	test(stack);
	return (EXIT_SUCCESS);
}
