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

	std::cout << "=== Testing addNumber() ===" << std::endl << std::endl;

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

	std::cout << "\n=== Testing Single Call using iterators ===" << std::endl << std::endl;

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

	std::cout << "\n=== Testing Single Call using random fill ===" << std::endl << std::endl;

	Span	autoVector(10000);

	autoVector.fillSpan();
	std::cout << "Vector size is " << autoVector.getVectorSize() << std::endl;
	try{
		autoVector.shortestSpan();
		autoVector.longestSpan();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
