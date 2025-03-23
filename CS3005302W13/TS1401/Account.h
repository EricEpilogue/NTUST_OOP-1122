/***********************************************************************
 * File: Account.h
 * Author: B11215002
 * Create Date: 2024/5/15
 * Editor: B11215002
 * Update Date: 2024/5/20
 * Description: This program is to test and catch the error for negative values
***********************************************************************/

#pragma once
#include <iostream>

class InsufficientFunds {
public:
	InsufficientFunds() {}
};

class NegativeDeposit {
public:
	NegativeDeposit() {}
};

class Account
{
private:
	double balance;
public:
	Account() { balance = 0; }
	Account(double initialDeposit) { balance = initialDeposit; }
	double getBalance() { return balance; }

	//returns new balance or -1 if error 
	double deposit(double amount)
	{
		if (amount < 0)
			throw NegativeDeposit();
		else 
			balance += amount;
		return balance;
	}

	//return new balance or -1 if invalid amount 
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0))
			throw InsufficientFunds();
		else 
			balance -= amount;
		return balance;
	}
};
