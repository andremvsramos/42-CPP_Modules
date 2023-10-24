/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:33:31 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 14:33:31 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &original) : AMateria(original._type) {}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &original) {
	(void)original;
	return (*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice* Ice::clone() const {
	return (new Ice(*this));
}
