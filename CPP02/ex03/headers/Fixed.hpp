/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:04 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 17:56:55 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					_fpNbr;
		static const int	_nBits = 8;

	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& original);
		Fixed&	operator=(const Fixed& original);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator>(const Fixed& to_compare);
		bool	operator<(const Fixed& to_compare);
		bool	operator>=(const Fixed& to_compare);
		bool	operator<=(const Fixed& to_compare);
		bool	operator==(const Fixed& to_compare);
		bool	operator!=(const Fixed& to_compare);
		Fixed	operator+(const Fixed& to_add);
		Fixed	operator-(const Fixed& to_sub);
		Fixed	operator*(const Fixed& to_mul);
		Fixed	operator/(const Fixed& to_div);
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		static Fixed&		min(Fixed& nbr1, Fixed& nbr2);
		static const Fixed&	min(const Fixed& nbr1, const Fixed& nbr2);
		static Fixed&		max(Fixed& nbr1, Fixed& nbr2);
		static const Fixed&	max(const Fixed& nbr, const Fixed& nbr2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif
