#include<iostream>

class BankAccount {
private:
	int balance = 0;
	static int total;
public:
	BankAccount() {
		balance += 0;
		total += 0;
	}

	BankAccount(int input) {
		balance = input;
		total += input;
	}
	void withdraw(int output) {
		balance -= output;
		total -= output;
	}
	void save(int input) {
		balance += input;
		total += input;
	}
	int getBalance() {
		return balance;
	}
	static int getAllMoneyInBank() {
		return total;
	}
};

int BankAccount::total = 0;