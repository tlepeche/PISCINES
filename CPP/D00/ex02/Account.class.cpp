/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 18:25:45 by tlepeche          #+#    #+#             */
/*   Updated: 2015/06/16 11:23:25 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <iomanip>

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";closed" << std::endl;
}

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) { return Account::_nbAccounts; }
int	Account::getTotalAmount(void) { return Account::_totalAmount; }
int	Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int	Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
int	Account::checkAmount(void) const { return this->_amount;}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";deposit:" << deposit
		<< ";amount:" << this->checkAmount() + deposit
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += this->_nbDeposits;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	if (this->checkAmount() - withdrawal >= 0)
	{
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->checkAmount()
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->checkAmount() - withdrawal
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += this->_nbWithdrawals;
		return true;
	}
	else
	{
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->checkAmount()
			<< ";withdrawal:refused"<< std::endl;
		return false;
	}
}


void	Account::_displayTimestamp(void) {
	time_t tps = time(0);
	struct tm * now = localtime( &tps );
	std::cout << "[" << std::put_time(now, "%Y%m%d") << "_" << std::put_time(now, "%H%M%S") << "] ";
}
