/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:06 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 16:45:51 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Fixed.hpp"

Fixed::Fixed() : _fpNbr(0) {
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& original) {
	std::cout << "Copy constructor called\n";
	_fpNbr = original.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& original) {
	std::cout << "Copy assignment operator called\n";
	if (this == &original)
		return (*this);
	_fpNbr = original.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_fpNbr);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_fpNbr = raw;
}
