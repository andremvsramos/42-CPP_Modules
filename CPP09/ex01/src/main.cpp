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

#include "../headers/RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "\033[1;31mERROR: Input must be as follows -> ./RPN \033[4m<mathematical_expression>\033[0m \nPlease, try again.\033[0m" << std::endl;
		return 1;
	}
	try {
		RPN	test(av[1]);
		//RPN test2;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
