/***********************************************************************
 * File: main.cpp
 * Author: B11215002
 * Create Date: 2024/5/15
 * Editor: B11215002
 * Update Date: 2024/5/20
 * Description: This program is to test the try&catch error implemented in Account.h
***********************************************************************/

#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
	Account a(100);
	try
	{
		cout << "Depositing 50" << endl;
		cout << "New balance: " << a.deposit(50) << endl;
		cout << "Withdraw 25" << endl;
		cout << "New balance: " << a.withdraw(25) << endl;
		cout << "Withdraw 250" << endl;
		cout << "New balance: " << a.withdraw(250) << endl;
	}
	catch (InsufficientFunds)
	{
		cout << "Not enough money to withdraw that amount." << endl;
	}
	catch (NegativeDeposit)
	{
		cout << "You may only deposit a positive amount." << endl;
	}
	cout << "Enter a character to exit" << endl;
	char wait;
	cin >> wait;
	return 0;
}