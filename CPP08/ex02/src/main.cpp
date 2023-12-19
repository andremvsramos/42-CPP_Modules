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

#include "../headers/MutantStack.hpp"
#include <list>

void	testMutantStack() {
	std::cout << "\n=== Testing MutantStack ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(77);
	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(120);
	mstack.push(123);
	mstack.push(12245);
	mstack.push(123666);
	mstack.push(0);

	MutantStack<int>::it itb = mstack.begin();
	MutantStack<int>::it ite = mstack.end();

	++itb;
	--ite;

	while (itb != ite)
	{
		std::cout << "begin: " << *itb << ", end: " << *ite << std::endl;
		++itb;
	}

	std::stack<int> s(mstack);
	std::stack<int> s2 = s;

}

void	testList() {
	std::cout << "\n=== Testing List ===" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(77);
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(120);
	list.push_back(123);
	list.push_back(12245);
	list.push_back(123666);
	list.push_back(0);

	std::list<int>::iterator itb = list.begin();
	std::list<int>::iterator ite = list.end();

	++itb;
	--ite;

	while (itb != ite)
	{
		std::cout << "begin: " << *itb << ", end: " << *ite << std::endl;
		++itb;
	}

	std::list<int> s(list);
}

int main( void ) {

	testMutantStack();
	testList();
	return 0;
}
