// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Account::Account(int initial_deposit)
{
}
Account::~Account(void)
{
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< " "
				<< "accounts:"
				<<
				<< ";total:"
				<<
				<< ";deposits:"
				<<
				<< ";withdrawals:"
				<<
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm* t = std::localtime(&now);
	std::cout 	<< "["
				<< (t->tm_year + 1900)
				<< (t->tm_mon + 1 < 10 ? "0" : "") << t->tm_mon + 1
				<< (t->tm_mday < 10 ? "0" : "") << t->tm_mday
				<< "_"
				<< (t->tm_hour < 10 ? "0" : "") << t->tm_hour
				<< (t->tm_min < 10 ? "0" : "") << t->tm_min
				<< (t->tm_sec < 10 ? "0" : "") << t->tm_sec
				<< "]";
}