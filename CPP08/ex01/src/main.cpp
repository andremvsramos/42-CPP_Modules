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

#include "../headers/Span.hpp"

int main( void ) {

	std::srand(std::time(NULL));

	Span s(10000);

	s.addNumber();
	s.addNumber();
	s.addNumber();
	s.addNumber();
	std::cout << "Vector size is " << s.getVectorSize() << std::endl;
	s.printVector();
	try{
		s.shortestSpan();
		s.longestSpan();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::vector<int> values;
	for (unsigned int i = static_cast<unsigned int>(s.getVectorSize()); i < s.getN(); i++)
		values.push_back(rand()%10000);

	s.fillSpan(values.begin(), values.end());
	std::cout << "Vector size is " << s.getVectorSize() << std::endl;
	try{
		s.shortestSpan();
		s.longestSpan();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}
