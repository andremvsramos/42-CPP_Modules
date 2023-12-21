/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:41:45 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/19 19:41:45 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"

/* ===================== Orthodox Canonical Form ===================== */

BitcoinExchange::BitcoinExchange() : _inName("default") {
	_dbFile.open("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & original)
	: _inName(original._inName) {
	_inFile.open(_inName.c_str());
	_dbFile.open("data.csv");
	_dbValues = original._dbValues;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & original) {
	if (this != &original) {
		_inName = original._inName;
		_inFile.open(_inName.c_str());
		_dbFile.open("data.csv");
		_dbValues = original._dbValues;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	_inFile.is_open() ? _inFile.close() : (void)0;
	_dbFile.is_open() ? _dbFile.close() : (void)0;
	_dbValues.clear();
}

/* ===================== Constructors ===================== */

BitcoinExchange::BitcoinExchange(std::string inputFile) {
	_inFile.open(inputFile.c_str());
	_dbFile.open("data.csv");
}

/* ===================== Member Functions ===================== */

void BitcoinExchange::doExchange() {
	dbConversion();
	inputConversion();
}

void BitcoinExchange::dbConversion() {
	try {
		!_dbFile.is_open() ? throw FileOpeningException() : 0;
		std::string dbContent;
		std::string	date;
		std::string	sValue;
		float		value;
		size_t		commaPos;
		while (!(dbContent = readFile(_dbFile)).empty()) {
			commaPos = dbContent.find(",");
			date = dbContent.substr(0, commaPos);
			sValue = dbContent.substr(commaPos + 1, dbContent.size());
			value = atof(sValue.c_str());
			_dbValues[date] = value;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::cout;
	}
}

void BitcoinExchange::inputConversion() {
	try {
		!_inFile.is_open() ? throw FileOpeningException() : 0;
		std::string	content;
		std::string	date;
		std::string	sValue;
		float		value;
		size_t		pipePos;
		int i = 0;
		while (!(content = readFile(_inFile)).empty()) {
			try {
				if (i == 0) { i = 1; continue; }
					pipePos = content.find("|");
				if (pipePos == std::string::npos) throw InvalidDateException(content);
				if (content[pipePos - 1] != ' ' && content[pipePos + 1] != ' ')
					throw InvalidDateException("Error: bad input => no \' | \' between date and value");
				date = checkDates(content.substr(0, pipePos - 1));
				sValue = content.substr(pipePos + 2, content.size());
				value = checkValue(sValue);
				exchangeRate(date, value);
			} catch (std::exception & e) {
				std::cout << e.what() << std::endl;
			}
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

std::string	BitcoinExchange::checkDates(const std::string & input) {
	int y = 0, m = 0, d = 0;
	input[4] != '-' || input[7] != '-' ? throw InvalidDateException(input) : 0;
	!isdigit(input[0]) && !isdigit(input[1]) && !isdigit(input[2]) && !isdigit(input[3]) ? throw InvalidDateException(input) : y = atoi((input.substr(0, 4)).c_str());
	!isdigit(input[5]) && !isdigit(input[6]) ? throw InvalidDateException(input) : m = atoi((input.substr(5, 7)).c_str());
	!isdigit(input[8]) && !isdigit(input[9]) ? throw InvalidDateException(input) : d = atoi((input.substr(8, input.size())).c_str());
	if (y < 0 || m < 1 || m > 12 || d < 1) throw InvalidDateException(input);
	static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m == 2 && isLeapYear(y)) daysInMonth[2] = 29;
	if (!(d <= daysInMonth[m])) throw InvalidDateException(input);
	return (input);
}

float	BitcoinExchange::checkValue(const std::string & input) {
	input.empty() ? throw InvalidValueException("Error: no value given.") : 0;
	float result = atof(input.c_str());
	result > 1000 ? throw InvalidValueException("Error: too large a number.") : 0;
	result < 0 ? throw InvalidValueException("Error: not a positive number.") : 0;
	return (result);
}

void	BitcoinExchange::exchangeRate(std::string dateToSearch, float valueToExchange) {
	std::string	date;
	float		exRate;
	std::map<std::string, float>::iterator it = _dbValues.find(dateToSearch);
	if (it != _dbValues.end())
		date = dateToSearch;
	else {
		for (it = _dbValues.begin(); it != _dbValues.end(); it++) {
			if (it->first >= dateToSearch) {
				date = it->first;
				break ;
			}
		}
	}
	exRate = _dbValues[date];
	std::cout << dateToSearch << " => " << valueToExchange << " = " << valueToExchange * exRate << std::endl;
}

bool	BitcoinExchange::isLeapYear(int year) {
	// Leap is must obey 3 conditions:
	//	 - Must be divisible by 4, it's a leap year.
	//	 - If it's also divisible by 100, it isn't, unless...
	//   - If the year is divisible by 400
	return ((!(year % 4) && !(year % 100)) || !(year % 400));
}

/* ===================== Exceptions ===================== */

const char *BitcoinExchange::FileOpeningException::what() const throw() {
	return ("File Exception: Cannot Open File");
}

const char *BitcoinExchange::ReadFileException::what() const throw() {
	return ("Read Exception: Cannot Read File");
}


BitcoinExchange::InvalidDateException::InvalidDateException(const std::string & error) {
	_errorMsg = "Error: bad input => " + error;
}

BitcoinExchange::InvalidDateException::~InvalidDateException() throw() {}

const char *BitcoinExchange::InvalidDateException::what() const throw() {
	return(_errorMsg.c_str());
}


BitcoinExchange::InvalidValueException::InvalidValueException(const std::string & error) {
	_errorMsg = error;
}

BitcoinExchange::InvalidValueException::~InvalidValueException() throw() {}

const char *BitcoinExchange::InvalidValueException::what() const throw() {
	return (_errorMsg.c_str());
}

/* ===================== Non-Member Functions ===================== */

std::string	readFile(std::ifstream & file) {
	std::string	input;

	if (!std::getline(file, input)) {
		if (file.eof())
			return "";
		else throw BitcoinExchange::ReadFileException();
	}
	return (input);
}
