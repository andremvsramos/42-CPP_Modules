/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:33:25 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/03 15:33:25 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :	_accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{

	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";ammount:" << _amount << ";created" << std::endl;
}

Account::~Account() {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";ammount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp() {

	std::time_t	now = std::time(NULL);
	std::tm		*now_time = std::localtime(&now);
	std::string TimeStamp;

	TimeStamp.resize(20);
	std::strftime(&TimeStamp[0], TimeStamp.size(), "%Y%m%d_%H%M%S", now_time);
	std::cout << "[" << TimeStamp << "]";
}

void	Account::makeDeposit(int deposit) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_witdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else {
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int	Account::getNbAccounts() {

	return (_nbAccounts);
}

int	Account::getTotalAmount() {

	return (_totalAmount);
}

int	Account::getNbDeposits() {

	return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {

	return (_totalNbWithdrawals);
}

int	Account::checkAmount() const {

	return (_amount);
}

void	Account::displayStatus() const{

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
				<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos() {

	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
