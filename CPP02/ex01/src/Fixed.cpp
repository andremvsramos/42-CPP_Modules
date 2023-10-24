/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:06 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 17:21:41 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Fixed.hpp"

Fixed::Fixed() : _fpNbr(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called\n";
	_fpNbr = nbr * (1 << _nBits);
}

Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called\n";
	_fpNbr = nbr * (1 << _nBits);
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

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_fpNbr) / static_cast<float>(1 << _nBits));
}

int	Fixed::toInt(void) const {
	return (_fpNbr / (1 << _nBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}
