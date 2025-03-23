/***********************************************************************
 * File: PrimeNumber.h
 * Author: B11215002
 * Create Date: 2024/4/12
 * Editor: B11215002
 * Update Date: 2024/4/12
 * Description: This program is to generate previous/next prime number by user choise
***********************************************************************/

#pragma once
#include <iostream>
class PrimeNumber {
public:
	int value;
public:
	//constructor
	PrimeNumber() {
		this->value = 1;
	}

	//input constructor
	PrimeNumber(int _value) {
		this->value = _value;
	}

	// Intent: get the current prime number 
	// Pre: use get() command
	// Post: returns the prime number of this class member
	int get() { return this->value; }

	// Intent: check whether a number is prime
	// Pre: insert a number
	// Post: return true or false
	bool isPrime(PrimeNumber num) {
		//only number > 1 can be prime number
		if (num.value <= 1) {
			return false;
		}

		//if it is divisible then false
		for (int i = 2; i * i <= num.value; ++i) {
			if (num.value % i == 0) {
				return false;
			}
		}
		return true;
	}

	// Intent: find the next prime number before return 
	// Pre: smaller prime number
	// Post: returns the next larger prime number
	PrimeNumber& operator++() {
		value += 1;

		while (!isPrime(value)) {
			value += 1;
		}

		return *this;
	}

	// Intent: return before finding the next prime number
	// Pre: smaller prime number
	// Post: returns the smaller prime number but storing the next larger one
	PrimeNumber operator++(int) {
		//store the value before change
		PrimeNumber pre(value);
		value += 1;

		while (!isPrime(value)) {
			value += 1;
		}

		//return the value before change
		return pre;
	}

	// Intent: find the previous prime number before return 
	// Pre: larger prime number
	// Post: returns the previous smaller prime number
	PrimeNumber& operator--() {
		//as required 
		if (this->value == 2) {
			value = 1;
			return *this;
		}

		value -= 1;

		while (!isPrime(value)) {
			value -= 1;
		}

		return *this;
	}

	// Intent: return before finding the previous smaller prime number
	// Pre: larger prime number
	// Post: returns the larger prime number but storing the next smaller one
	PrimeNumber operator--(int) {
		if (this->value == 2) {
			value = 1;
			return *this;
		}

		//store the value before change
		PrimeNumber pre(value);

		value -= 1;

		while (!isPrime(value)) {
			value -= 1;
		}

		//output pre-changed value
		return pre;
	}

};