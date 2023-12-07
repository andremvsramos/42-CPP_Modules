/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:07:54 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 11:31:11 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <stdint.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# pragma once

typedef struct s_data {
    std::string secretMessage;
    size_t      hiddenChars;
}               Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& original);
        Serializer&    operator=(const Serializer& original);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data*     deserialize(uintptr_t raw);
};

#endif
