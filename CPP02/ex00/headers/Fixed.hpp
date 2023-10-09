/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:04 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 16:33:07 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Fixed
{
	private:
		int					_fpNbr;
		static const int	_nBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& original);
		Fixed&	operator=(const Fixed& original);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif
