/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:45:04 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 11:45:46 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/C.hpp"

/* ===================== Orthodox Canonical Form ===================== */

C::C () {}

C::C (const C& original) {
    static_cast<void>(original);
}

C &C::operator=(const C& original) {
    static_cast<void>(original);
    return (*this);
}

C::~C () {}
