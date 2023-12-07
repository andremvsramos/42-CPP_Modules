/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:51 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 12:10:54 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"

/* ===================== Orthodox Canonical Form ===================== */

ScalarConverter::ScalarConverter () {}

ScalarConverter::ScalarConverter (const ScalarConverter& original) {
    static_cast<void>(original);
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& original) {
    static_cast<void>(original);
    return (*this);
}

ScalarConverter::~ScalarConverter () {}

/* ===================== Member functions ===================== */

            /* ===================== Data type checkers ===================== */

            bool    ScalarConverter::isChar(const std::string & str) {
                if (str.size() != 1)
                    return (false);
                if (str[0]>= '0' && str[0] <= '9')
                    return (false);
                if (str[0] >= 32 && str[0] <= 127)
                    return (true);
                return (false);
            }

            bool    ScalarConverter::isInt(const std::string & str) {
                for (size_t i = 0; i < str.length(); i++) {
                    if (!i && str[i] == '-')
                        continue;
                    if (!isdigit(str[i]))
                        return (false);
                }
                return (true);
            }

            bool    ScalarConverter::isFloat(const std::string & str) {
                if (str[str.length() - 1] != 'f')
                    return (false);
                if (str.find_first_of('.') != str.find_last_of('.') || std::string::npos)
                    return (false);

                for (size_t i = 0; i < str.length() - 1; i++) {
                    if (!i && str[i] == '-')
                        continue;
                    if (str[i] == '.')
                        continue;
                    if (!isdigit(str[i]))
                        return (false);
                }
                return (true);
            }

            bool    ScalarConverter::isDouble(const std::string & str) {
                if (str.find_first_of('.') != str.find_last_of('.') || str.find('.') == std::string::npos)
                    return (false);
                for (size_t i = 0; i < str.length() - 1; i++) {
                    if (!i && str[i] == '-')
                        continue;
                    if (str[i] == '.') {
                        if (!isdigit(str[i + 1]) && !isdigit(str[i - 1]))
                            return (false);
                        continue;
                    }
                    if (!isdigit(str[i]))
                        return (false);
                }
                return (true);
            }

            bool    ScalarConverter::isPseudo(const std::string & str) {
                if (str == "-inff" || str == "+inff" || str == "nanf" ||
                    str == "-inf" || str == "+inf" || str == "nan")
                        return (true);
                return (false);
            }

            /* ===================== Data type printers ===================== */

            void    ScalarConverter::printChar(const char c, const std::string & str) {
                if (checkOverflow(str, CHAR))
                    std::cout << "Char: Overflow" << std::endl;
                else if (isprint(c))
                    std::cout << "Char: '" << c << "'" << std::endl;
                else
                    std::cout << "Char: Non displayable" << std::endl;
            }

            void    ScalarConverter::printInt(int i, const std::string & str) {
                if (checkOverflow(str, INT))
                    std::cout << "Int: Overflow" << std::endl;
                else
                    std::cout << "Int: " << i << std::endl;
            }

            void    ScalarConverter::printFloat(float f, const std::string & str) {
                if (checkOverflow(str, FLOAT))
                    std::cout << "Float: Overflow" << std::endl;
                else
                    std::cout << "Float: " << f << "f" << std::endl;
            }

            void    ScalarConverter::printDouble(double d, const std::string & str) {
                if (checkOverflow(str, DOUBLE))
                    std::cout << "Double: Overflow" << std::endl;
                else
                    std::cout << "Double: " << d << std::endl;
            }

            void    ScalarConverter::printPseudo(const std::string & str) {
                std::cout << "Char: Impossible" << std::endl;
                std::cout << "Int: Impossible" << std::endl;

                if (str.find("nan") != std::string::npos) {
                    std::cout << "Float: nanf" << std::endl;
                    std::cout << "Double: nan" << std::endl;
                }
                else {
                    std::cout << "Float: " << str[0] << "inff" << std::endl;
                    std::cout << "Double: " << str[0] << "inf" << std::endl;
                }
            }

            void    ScalarConverter::printInput(const long double num, const std::string & str) {
                printChar(static_cast<char>(num), str);
                printInt(static_cast<int>(num), str);
                printFloat(static_cast<float>(num), str);
                printDouble(static_cast<double>(num), str);
            }

            /* ===================== Overflow security ===================== */

            bool    ScalarConverter::checkOverflow(const std::string & str, const t_type type) {
                long double num = std::strtold(str.c_str(), NULL);
                switch (type) {
                    case CHAR:
                        return (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min());
                    case INT:
                        return (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min());
                    case FLOAT:
                        return (num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max());
                    case DOUBLE:
                        return (num > std::numeric_limits<double>::max() || num < -std::numeric_limits<double>::max());
                    default:
                        return (false);
                }
            }

void    ScalarConverter::convert(const std::string & str) {
    if (isChar(str))
        printInput(str[0], str);
    else if (isInt(str))
        printInput(std::strtod(str.c_str(), NULL), str);
    else if (isFloat(str))
        printInput(std::strtod(str.c_str(), NULL), str);
    else if (isDouble(str))
        printInput(std::strtod(str.c_str(), NULL), str);
    else if (isPseudo(str))
        printPseudo(str);
    else
        std::cerr << "Error: Invalid Type" << std::endl;
}
