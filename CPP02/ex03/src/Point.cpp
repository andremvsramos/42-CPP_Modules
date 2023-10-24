/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:05:08 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/10 09:50:44 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const nbr1, float const nbr2) : _x(nbr1), _y(nbr2) {}

Point::Point(const Point& original) : _x(original._x), _y(original._y) {}

Point &Point::operator=(const Point& original) {
	if (this == &original)
		return (*this);
	(Fixed)_x = original.getX();
	(Fixed)_y = original.getY();
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const {
	return (_x);
}

Fixed Point::getY() const {
	return (_y);
}

float Point::getAxisX() const {
	return (_x.toFloat());
}

float Point::getAxisY() const {
	return (_y.toFloat());
}
