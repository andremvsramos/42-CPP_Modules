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
	_dbFile.open("../data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & original)
	: _inName(original._inName) {
	_inFile.open(_inName.c_str());
	_dbFile.open("../data.csv");
	_dbValues = original._dbValues;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & original) {
	if (this != &original) {
		_inName = original._inName;
		_inFile.open(_inName.c_str());
		_dbFile.open("../data.csv");
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
	_dbFile.open("../data.csv");
}

/* ===================== Member Functions ===================== */

void BitcoinExchange::dbConversion() {
	!_dbFile.is_open() ? throw FileOpeningException() : 0;
	std::string dbContent;
	std::string	date;
	std::string	sValue;
	float		value;
	size_t		commaPos;
	while (!readFile(_dbFile).empty()) {
		commaPos = dbContent.find(",");
		date = dbContent.substr(0, commaPos);
		sValue = dbContent.substr(commaPos + 1, dbContent.size());
		value = atof(sValue.c_str());
		std::cout << "Date: " << date << " | Value: " << std::setprecision(7) << value << std::endl;
		_dbValues[date] = value;
	}
}

/* ===================== Exceptions ===================== */

const char *BitcoinExchange::FileOpeningException::what() const throw() {
	return ("File Exception: Cannot Open File");
}

const char *BitcoinExchange::ReadFileException::what() const throw() {
	return ("Read Exception: Cannot Read File");
}

/* ===================== Non-Member Functions ===================== */

std::string	readFile(std::ifstream & file) {
	std::string	input;

	while (input.empty())
		std::getline(file, input) == 0 ? throw BitcoinExchange::ReadFileException() : 0;
	return (input);
}
