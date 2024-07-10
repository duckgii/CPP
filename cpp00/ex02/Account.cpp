#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
	//return Account::_totalNbWithdrawals;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts()<<";amount:"<<getTotalAmount()<<";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<"deposits:"<<deposit;
	_amount += deposit;
	std::cout<<";amount:"<<_amount<<";nb_deposit"<<_nbDeposits<<std::endl;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int widhdrawal)
{
	_displayTimestamp();
	if (_amount < widhdrawal)
	{
		std::cout<<"index:"<<_accountIndex<<"p_amount:"<<_amount<<"withdrawal:falsed"<<std::endl;
		return (false);
	}
	_nbWithdrawals++;
	std::cout<<"index:"<<_accountIndex<<"p_amount:"<<_amount<<"withdrawal:"<<widhdrawal;
	_amount -= widhdrawal;
	std::cout<<";amount:"<<_amount<<"nb_withdrawals"<<_nbWithdrawals<<std::endl;
	_totalAmount -= widhdrawal;
	return (true);
}

int	Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:;"<<_nbDeposits<<"withdrawals:"<<_nbWithdrawals<<std::endl;
}

void	Account::_displayTimestamp()
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	std::cout<<"[" << (now->tm_year + 1900);
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << (now->tm_mon + 1);
	std::cout.width(2);
	std::cout.fill('0');
	std::cout <<  now->tm_mday <<"_";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << now->tm_hour;
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << now->tm_min;
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << now->tm_sec << "] ";
}