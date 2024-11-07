/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:05 by zbakkas           #+#    #+#             */
/*   Updated: 2024/11/07 16:59:06 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>


int	Account:: _nbAccounts =0;
int	Account:: _totalAmount=0;
int	Account:: _totalNbDeposits=0;
int	Account:: _totalNbWithdrawals=0;

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}
int Account ::getTotalAmount( void )
{
    return _totalAmount;
}
int Account ::	getNbDeposits( void )
{
    return _totalNbDeposits;
}
int Account ::	getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

void Account :: displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:"<< _nbAccounts << ";"; 
    std::cout << "total:"<< _totalAmount << ";"; 
    std::cout << "deposits:"<< _totalNbDeposits << ";"; 
    std::cout << "withdrawals:"<< _totalNbWithdrawals << ";\n"; 
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
 	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amout:" << _amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amout:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}




bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amout:" << _amount << ";";
		std::cout << "withdrawal:refused" << '\n';
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amout:" << _amount + withdrawal << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void    Account::_displayTimestamp(void)
{
       // Get the current time
    std::time_t now = std::time(nullptr);

    // Convert to local time
    std::tm* local_time = std::localtime(&now);

    // Format and display the timestamp
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local_time);
    std::cout << "[" << buffer << "] " ;
};