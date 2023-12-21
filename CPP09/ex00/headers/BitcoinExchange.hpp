/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:32:03 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/19 19:32:03 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <stdlib.h>
# include <map>

class BitcoinExchange {
	private:
		std::string		_inName;
		std::ifstream	_inFile;
		std::ifstream	_dbFile;
		std::map<std::string, float>	_dbValues;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & original);
		BitcoinExchange & operator=(const BitcoinExchange & original);
		~BitcoinExchange();


		BitcoinExchange(std::string	inputFile);

		void	doExchange();
		void	dbConversion();
		void	inputConversion();
		std::string	checkDates(const std::string & input);
		float	checkValue(const std::string & input);

		void	exchangeRate(std::string dateToSearch, float valueToExchange);

		bool	isLeapYear(int year);

		class	FileOpeningException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	ReadFileException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	InvalidDateException : public std::exception {
			private:
				std::string	_errorMsg;
			public:
				InvalidDateException(const std::string & error);
				~InvalidDateException() throw();
				virtual const char *what() const throw();
		};

		class	InvalidValueException : public std::exception {
			private:
				std::string _errorMsg;
			public:
				InvalidValueException(const std::string & error);
				~InvalidValueException() throw();
				virtual const char *what() const throw();
		};
};

std::string	readFile(std::ifstream & file);

#endif
