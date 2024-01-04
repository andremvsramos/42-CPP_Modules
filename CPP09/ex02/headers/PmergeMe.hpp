/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:40:03 by andvieir          #+#    #+#             */
/*   Updated: 2024/01/04 15:40:03 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <algorithm>
# include <iterator>
# include <vector>
# include <deque>
# include <fstream>
# include <sstream>
#include <climits>
#include <ctime>

class PmergeMe {

	private:
		std::vector<int> _vectorStack;
		std::deque<int>	_dequeStack;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe & original);
		PmergeMe & operator=(const PmergeMe & original);
		~PmergeMe();

		PmergeMe(std::vector<int> vec);

		void	sortContainers();

		void	mergeVector(std::vector<int> & vec);
		void	sortVector(std::vector<int> & left, std::vector<int> & right, std::vector<int> & vec);
		void	printVector();

		void	mergeDeque(std::deque<int> & deq);
		void	sortDeque(std::deque<int> & left, std::deque<int> & right, std::deque<int> & deq);
		void	printDeque();

};

#endif
