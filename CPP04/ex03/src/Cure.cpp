/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:40:28 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/24 14:40:28 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &original) : AMateria(original._type) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &original) {
	(void)original;
	return (*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

