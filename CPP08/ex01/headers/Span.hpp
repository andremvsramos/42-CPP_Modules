/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:57:57 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/18 19:55:03 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# pragma once

# include <iostream>
# include <ctime>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <limits>

class Span
{

    private:
        unsigned int N;
        std::vector<int> _values;
        std::vector<int>::iterator it;

    public:
        Span();
        Span(const Span& original);
        Span&    operator=(const Span& original);
        ~Span();

        Span(unsigned int N);

        void addNumber();
        void shortestSpan();
        void longestSpan();
        void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        size_t getVectorSize();
        unsigned int     getN();

        void    printVector();

        class ElementLimitReachedException : public std::exception {
            public:
               virtual const char *what() const throw();
        };

        class NoSpanException : public std::exception {
            public:
               virtual const char *what() const throw();
        };

};

#endif
