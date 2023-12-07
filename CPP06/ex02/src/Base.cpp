/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:52 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 12:06:08 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Base.hpp"
#include "../headers/A.hpp"
#include "../headers/B.hpp"
#include "../headers/C.hpp"

/* ===================== Virutal Destructor ===================== */

Base::~Base () {}

/* ===================== Non-Member Functions ===================== */

Base *generate(void) {
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class is A type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class is B type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class is C type" << std::endl;
}

void	identify(Base& p){
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Class is A type" << std::endl;
	} catch (std::exception &e) {} // Can also use (std::bad_cast &e)

	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "Class is B type" << std::endl;
	} catch (std::exception &e) {}

	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "Class is C type" << std::endl;
	} catch (std::exception &e) {}
}
