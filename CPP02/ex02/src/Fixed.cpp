/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:06 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 18:01:58 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Fixed.hpp"

Fixed::Fixed() : _fpNbr(0) {}

Fixed::Fixed(const int nbr) {
	_fpNbr = nbr * (1 << _nBits);
}

Fixed::Fixed(const float nbr) {
	_fpNbr = nbr * (1 << _nBits);
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& original) {
	_fpNbr = original.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& original) {
	if (this == &original)
		return (*this);
	_fpNbr = original.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (_fpNbr);
}

void	Fixed::setRawBits(int const raw) {
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


bool	Fixed::operator>(const Fixed& to_compare) {
	return (_fpNbr > to_compare.getRawBits());
}

bool	Fixed::operator<(const Fixed& to_compare) {
	return (_fpNbr < to_compare.getRawBits());
}

bool	Fixed::operator>=(const Fixed& to_compare) {
	return (_fpNbr >= to_compare.getRawBits());
}

bool	Fixed::operator<=(const Fixed& to_compare) {
	return (_fpNbr <= to_compare.getRawBits());
}

bool	Fixed::operator==(const Fixed& to_compare) {
	return (_fpNbr == to_compare.getRawBits());
}

bool	Fixed::operator!=(const Fixed& to_compare) {
	return (_fpNbr != to_compare.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& to_add) {
	return (_fpNbr + to_add.getRawBits());
}

Fixed	Fixed::operator-(const Fixed& to_sub) {
	return (_fpNbr - to_sub.getRawBits());
}

Fixed	Fixed::operator*(const Fixed& to_mul) {
	return (_fpNbr * to_mul.getRawBits());
}

Fixed	Fixed::operator/(const Fixed& to_div) {
	return (_fpNbr / to_div.getRawBits());
}

//++a
Fixed&	Fixed::operator++(void) {
	return (_fpNbr += 1, *this);
}

//a++
Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	return (_fpNbr += 1, temp);
}

//--a
Fixed&	Fixed::operator--(void) {
	return (_fpNbr -= 1, *this);
}

//a--
Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	return (_fpNbr -= 1, temp);
}

Fixed	&Fixed::min(Fixed& nbr1, Fixed& nbr2) {
	if (nbr1.toFloat() < nbr2.toFloat())
		return (nbr1);
	return (nbr2);
}

Fixed	const &Fixed::min(const Fixed& nbr1, const Fixed& nbr2) {
	if (nbr1.toFloat() < nbr2.toFloat())
		return (nbr1);
	return (nbr2);
}

Fixed	&Fixed::max(Fixed& nbr1, Fixed& nbr2) {
	if (nbr1.toFloat() < nbr2.toFloat())
		return (nbr2);
	return (nbr1);
}

Fixed	const &Fixed::max(const Fixed& nbr1, const Fixed& nbr2) {
	if (nbr1.toFloat() < nbr2.toFloat())
		return (nbr2);
	return (nbr1);
}
