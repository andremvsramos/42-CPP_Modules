/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:41:11 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/10 09:37:50 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/bsp.hpp"


float	area(float x1, float y1, float x2, float y2, float x3, float y3) {
	return (fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	float	ax, ay, bx, by, cx, cy, px, py;

	ax = a.getAxisX();
	ay = a.getAxisY();
	bx = b.getAxisX();
	by = b.getAxisY();
	cx = c.getAxisX();
	cy = c.getAxisY();
	px = point.getAxisX();
	py = point.getAxisY();

	float	abcArea = area(ax, ay, bx, by, cx, cy);
	float	pbcArea = area(px, py, bx, by, cx, cy);
	float	apcArea = area(ax, ay, px, py, cx, cy);
	float	abpArea = area(ax, ay, bx, by, px, py);
	if (!pbcArea || !apcArea || !abpArea)
		return (false);
	if (abcArea == (pbcArea + apcArea + abpArea))
		return (true);
	return (false);
}
