/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:40:36 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/10 09:38:21 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
# define BSP_HPP

#include "Point.hpp"

float	area(float x1, float y1, float x2, float y2, float x3, float y3);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
