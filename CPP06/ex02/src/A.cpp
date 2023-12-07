/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:34 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 11:44:35 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/A.hpp"

/* ===================== Orthodox Canonical Form ===================== */

A::A () {}

A::A (const A& original) {
    static_cast<void>(original);
}

A &A::operator=(const A& original) {
    static_cast<void>(original);
    return (*this);
}

A::~A () {}
