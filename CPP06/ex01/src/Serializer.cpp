/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:07:51 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 11:28:12 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Serializer.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Serializer::Serializer () {}

Serializer::Serializer (const Serializer& original) {
    static_cast<void>(original);
}

Serializer &Serializer::operator=(const Serializer& original) {
    static_cast<void>(original);
    return (*this);
}

Serializer::~Serializer () {}

/* ===================== Member functions ===================== */

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
