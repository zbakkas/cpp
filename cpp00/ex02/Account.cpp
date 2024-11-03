#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

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
void Account :: displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:"<< _nbAccounts << ";"; 
    std::cout << "total:"<< _totalAmount << ";"; 
    std::cout << "deposits:"<< _totalNbDeposits << ";"; 
    std::cout << "withdrawals:"<< _totalNbWithdrawals << ";"; 
}

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts++;
	std::cout << "index" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
 	this->_nbDeposits++;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amout:" << this->_amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amout:" << this->_amount << ";";
	std::cout << "nb_deposits" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    this->_displayTimestamp();
	if (this->_amount < withdrawal)
	{
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amout:" << this->_amount << ";";
		std::cout << "withdrawal:refused" << '\n';
		return false;
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amout:" << this->_amount + withdrawal << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals" << this->_nbWithdrawals << std::endl;
	return true;
}
int		Account::checkAmount( void ) const
{
    return this->_amount;
}
void	Account::displayStatus( void ) const
{
    this->_displayTimestamp();
	std::cout << "index" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void)
{
    //  // Get the current time
    // auto now = std::chrono::system_clock::now();
    
    // // Convert to a time_t to format it into a readable format
    // std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    
    // // Convert time_t to tm struct for formatting
    // std::tm local_tm = *std::localtime(&now_time);
    
    // // Display the timestamp in "YYYY-MM-DD HH:MM:SS" format
    // std::cout << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S") << std::endl;


       // Get the current time
    std::time_t now = std::time(nullptr);

    // Convert to local time
    std::tm* local_time = std::localtime(&now);

    // Format and display the timestamp
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
    std::cout << "[" << buffer << "]" << std::endl;
};