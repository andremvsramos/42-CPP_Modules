/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:48 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/22 11:11:01 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# pragma once

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& original);
        ScalarConverter&    operator=(const ScalarConverter& original);
        ~ScalarConverter();

    public:

        typedef enum {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            PSEUDO
        } t_type;

        static bool isChar(const std::string & str);
        static bool isInt(const std::string & str);
        static bool isFloat(const std::string & str);
        static bool isDouble(const std::string & str);
        static bool isPseudo(const std::string & str);

        static bool checkOverflow(const std::string & str, const t_type type);

        static void convert(const std::string & str);

        static void printChar(const char c,const std::string & str);
        static void printInt(int i,const std::string & str);
        static void printFloat(float f,const std::string & str);
        static void printDouble(double d,const std::string & str);
        static void printPseudo(const std::string & str);
        static void printInput(const long double num, const std::string & str);
};

#endif
