#include <iostream>
#include "BankAccount.h"

int balance = 0;
using namespace std;

int main() {
	BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
	cout << BankAccount::getAllMoneyInBank() << endl;//100
	bankAccount1.withdraw(100);
	cout << bankAccount1.getBalance() << endl;//100
	cout << BankAccount::getAllMoneyInBank() << endl;//0
	bankAccount2.save(50);
	cout << bankAccount2.getBalance() << endl;//50
	cout << BankAccount::getAllMoneyInBank() << endl;//50
	return 0;
}
