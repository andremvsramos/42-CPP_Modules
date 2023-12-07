/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:30 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 11:44:31 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/B.hpp"

/* ===================== Orthodox Canonical Form ===================== */

B::B () {}

B::B (const B& original) {
    static_cast<void>(original);
}

B &B::operator=(const B& original) {
    static_cast<void>(original);
    return (*this);
}

B::~B () {}
