/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:11:30 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/07 18:08:46 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

# pragma once

template <typename T>
class Array
{
    private:
        T*      _array;
        size_t  _size;

    public:
        Array();
        Array(const Array& original);
        Array&    operator=(const Array& original);
        ~Array();

        Array(unsigned int n);

        unsigned int    size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        T&  operator[](unsigned int index) const;
        // Array&  operator[](int index);
};


template <typename T>
std::ostream    &operator<<(std::ostream& out, const Array<T>& array);

# include "../src/Array.tpp"

#endif
