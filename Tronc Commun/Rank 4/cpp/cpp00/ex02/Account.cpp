/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:52:08 by bastienverd       #+#    #+#             */
/*   Updated: 2024/08/19 18:55:54 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <cstdarg>
#include <ctime>
#include <iostream>

void __printLog(int count, ...)
{
	va_list	args;
	va_start( args, count );

	for ( ; count > 1; count -= 2 ) {
		const char	*str = va_arg( args, const char * );
		int			value = va_arg( args, int );
		std::cout << str << ":" << value;
		if ( count > 2 )
			std::cout << ";";
	}
	if ( count == 1 ) {
		const char	*str = va_arg( args, const char * );
		std::cout << str;
	}
	std::cout << std::endl;
	va_end( args );
}

#define PRINT(count, ...) { \
	(_displayTimestamp()); \
	(__printLog( count, __VA_ARGS__ )); \
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) { return ( _nbAccounts ); }
int	Account::getTotalAmount( void ) { return ( _totalAmount ); }
int	Account::getNbDeposits( void ) { return ( _totalNbDeposits ); }
int	Account::getNbWithdrawals( void ) { return ( _totalNbWithdrawals ); }
int	Account::checkAmount( void ) const { return ( _amount ); }

void	Account::displayAccountsInfos( void ) {
	PRINT( 8, "accounts", _nbAccounts, "total", _totalAmount, "deposits", _totalNbDeposits, "withdrawals", _totalNbWithdrawals );
}

void	Account::displayStatus( void ) const {
	PRINT( 8, "index", _accountIndex, "amount", _amount, "deposits", _nbDeposits, "withdrawals", _nbWithdrawals );
}

void	Account::_displayTimestamp( void ) {
	time_t		t = time( 0 );
	struct tm	*now = localtime( &t );

	std::cout << "[" << ( now->tm_year + 1900 )
			  << ( now->tm_mon + 1 < 10 ? "0" : "" ) << now->tm_mon + 1
			  << ( now->tm_mday < 10 ? "0" : "" ) << now->tm_mday << "_"
			  << ( now->tm_hour < 10 ? "0" : "" ) << now->tm_hour
			  << ( now->tm_min < 10 ? "0" : "" ) << now->tm_min
			  << ( now->tm_sec < 10 ? "0" : "" ) << now->tm_sec << "] ";
}

void	Account::makeDeposit( int deposit ) {
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	PRINT(10, "index", _accountIndex, "p_amount", _amount - deposit, "deposit", deposit, "amount",
		_amount, "nb_deposits", _nbDeposits);
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal > _amount) {
		PRINT(5, "index", _accountIndex, "p_amount", _amount, "withdrawal:refused");
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	PRINT(10, "index", _accountIndex, "p_amount", _amount + withdrawal, "withdrawal", withdrawal, "amount", _amount, "nb_withdrawals", _nbWithdrawals);
	return (true);
}

Account::Account( int initial_deposit )
		: _accountIndex( _nbAccounts++ ),
		_amount( initial_deposit ),
		_nbDeposits( 0 ),
		_nbWithdrawals( 0 ) {
	_totalAmount += initial_deposit;
	PRINT( 5, "index", _accountIndex, "amount", _amount, "created" );
}

Account::~Account( void ) {
	PRINT( 5, "index", _accountIndex, "amount", _amount, "closed" );
}
