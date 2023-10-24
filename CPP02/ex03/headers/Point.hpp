/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:05:11 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/10 09:51:04 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point();
	Point(float const nbr1, float const nbr2);
	Point(const Point& original);
	Point&	operator=(const Point& original);
	~Point();
	Fixed	getX() const;
	Fixed	getY() const;
	float	getAxisX() const;
	float	getAxisY() const;
};

#endif
