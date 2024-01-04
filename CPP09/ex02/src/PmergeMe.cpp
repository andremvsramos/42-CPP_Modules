/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:47:54 by andvieir          #+#    #+#             */
/*   Updated: 2024/01/04 15:47:54 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"

/* ===================== Orthodox Canonical Form ===================== */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & original) :
	_vectorStack(original._vectorStack), _dequeStack(original._dequeStack) {}

PmergeMe & PmergeMe::operator=(const PmergeMe & original) {
	if (this != &original) {
		_vectorStack = original._vectorStack;
		_dequeStack = original._dequeStack;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* ===================== Constructors ===================== */

PmergeMe::PmergeMe(std::vector<int> vec) :
	_vectorStack(vec), _dequeStack(vec.begin(), vec.end()) {
		std::cout << "\033[0;31mBefore: \033[0m";
		std::vector<int>::iterator	it;
		for (it = _vectorStack.begin(); it != _vectorStack.end(); it++)
			std::cout << *it << " ";
		std::cout << "\n" << std::endl;
		sortContainers();
}

/* ===================== Member Functions ===================== */

void	PmergeMe::sortContainers() {
	clock_t	startVector = clock();
	mergeVector(_vectorStack);
	clock_t	endVector = clock();
	double	deltaTimeVector = 1000.0 * (endVector - startVector) / CLOCKS_PER_SEC;
	printVector();
	std::cout << "Time to process a range of " << _vectorStack.size()
		<< " elements with std::vector : " << std::fixed << std::setprecision(6) << deltaTimeVector << "us" << std::endl;

	std::cout << std::endl;

	clock_t	startDeque = clock();
	mergeDeque(_dequeStack);
	clock_t	endDeque = clock();
	double	deltaTimeDeque = 1000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;
	printDeque();
	std::cout << "Time to process a range of " << _dequeStack.size()
		<< " elements with std::deque : " << std::fixed << std::setprecision(6) << deltaTimeDeque << "us" << std::endl;
}

void	PmergeMe::mergeVector(std::vector<int> & vec) {
	if (vec.size() == 1) return ;
	int	middle = vec.size() / 2;

	std::vector<int> left = std::vector<int>(vec.begin(), vec.begin() + middle);
	std::vector<int> right = std::vector<int>(vec.begin() + middle, vec.end());
	mergeVector(left);
	mergeVector(right);
	sortVector(left, right, vec);
}

void	PmergeMe::mergeDeque(std::deque<int> & deq) {
	if (deq.size() == 1) return ;
	int	middle = deq.size() / 2;
	std::deque<int> left = std::deque<int>(deq.begin(), deq.begin() + middle);
	std::deque<int> right = std::deque<int>(deq.begin() + middle, deq.end());
	mergeDeque(left);
	mergeDeque(right);
	sortDeque(left, right, deq);
}

void	PmergeMe::sortVector(std::vector<int> & left, std::vector<int> & right, std::vector<int> & vec) {
	size_t l = 0, r = 0, i = 0;

	while (l < left.size() && r < right.size()) {
		if (left[l] < right[r]) vec[i++] = left[l++];
		else vec[i++] = right[r++];
	}
	while (l < left.size())
		vec[i++] = left[l++];
	while (r < right.size())
		vec[i++] = right[r++];
}

void	PmergeMe::sortDeque(std::deque<int> & left, std::deque<int> & right, std::deque<int> & deq) {
	size_t l = 0, r = 0, i = 0;

	while (l < left.size() && r < right.size()) {
		if (left[l] < right[r]) deq[i++] = left[l++];
		else deq[i++] = right[r++];
	}
	while (l < left.size())
		deq[i++] = left[l++];
	while (r < right.size())
		deq[i++] = right[r++];
}

void	PmergeMe::printVector() {
	std::vector<int>::iterator it;
	std::cout << "\033[1;33mAfter Algorithm[VECTOR]: \033[0m";
	for(it = _vectorStack.begin(); it < _vectorStack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printDeque() {
	std::deque<int>::iterator it;
	std::cout << "\033[1;33mAfter Algorithm[DEQUE]: \033[0m";
	for(it = _dequeStack.begin(); it < _dequeStack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
