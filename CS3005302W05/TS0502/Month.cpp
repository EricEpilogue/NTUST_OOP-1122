/***********************************************************************
 * File: Month.cpp
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to design functions
***********************************************************************/

#include "Month.h"
#include <iostream>
#include <string>

// Intent: default constructor
Month::Month()
{
	this->month = 1;
}

// Intent: default constructor with char input
Month::Month(char first, char second, char third)
{
	if (first == 'J' && second == 'a' && third == 'n') {
		this->month = 1;
	}
	else if (first == 'F' && second == 'e' && third == 'b') {
		this->month = 2;
	}
	else if (first == 'M' && second == 'a' && third == 'r') {
		this->month = 3;
	}
	else if (first == 'A' && second == 'p' && third == 'r') {
		this->month = 4;
	}
	else if (first == 'M' && second == 'a' && third == 'y') {
		this->month = 5;
	}
	else if (first == 'J' && second == 'u' && third == 'n') {
		this->month = 6;
	}
	else if (first == 'J' && second == 'u' && third == 'l') {
		this->month = 7;
	}
	else if (first == 'A' && second == 'u' && third == 'g') {
		this->month = 8;
	}
	else if (first == 'S' && second == 'e' && third == 'p') {
		this->month = 9;
	}
	else if (first == 'O' && second == 'c' && third == 't') {
		this->month = 10;
	}
	else if (first == 'N' && second == 'o' && third == 'v') {
		this->month = 11;
	}
	else if (first == 'D' && second == 'e' && third == 'c') {
		this->month = 12;
	}
}

// Intent: default constructor with int input
Month::Month(int monthInt)
{
	this->month = monthInt;
	if (this->month < 1 || this->month > 12) {
		this->month = 1;
	}
}

// Intent: I actually don't know
Month::~Month()
{
	
}

// Intent: To get input of the month value
// Pre: input could be not a correct money value
// Post: check and store the value if correct
void Month::inputInt()
{
	int number = 0;

	std::cin >> number;

	if (number < 1 || number > 12) {
		number = 1;
	}

	this->month = number;
}

// Intent: To get input of the month abbreviation
// Pre: input could be incorrect that doesn't correspond to a month
// Post: check and store the month value if correct
void Month::inputStr()
{
	char first;
	char second;
	char third;
	std::cin >> first >> second >> third;

	if (first == 'J' && second == 'a' && third == 'n') {
		this->month = 1;
	}
	else if (first == 'F' && second == 'e' && third == 'b') {
		this->month = 2;
	}
	else if(first == 'M' && second == 'a' && third == 'r') {
		this->month = 3;
	}
	else if (first == 'A' && second == 'p' && third == 'r') {
		this->month = 4;
	}
	else if (first == 'M' && second == 'a' && third == 'y') {
		this->month = 5;
	}
	else if (first == 'J' && second == 'u' && third == 'n') {
		this->month = 6;
	}
	else if (first == 'J' && second == 'u' && third == 'l') {
		this->month = 7;
	}
	else if (first == 'A' && second == 'u' && third == 'g') {
		this->month = 8;
	}
	else if (first == 'S' && second == 'e' && third == 'p') {
		this->month = 9;
	}
	else if (first == 'O' && second == 'c' && third == 't') {
		this->month = 10;
	}
	else if (first == 'N' && second == 'o' && third == 'v') {
		this->month = 11;
	}
	else if (first == 'D' && second == 'e' && third == 'c') {
		this->month = 12;
	}
	else {
		this->month = 1;
	}
}

// Intent: To output the month value
// Pre: nothing
// Post: print the called month, if it's invalid, print 1
void Month::outputInt()
{
	if (this->month < 1 || this->month > 12) {
		this->month = 1;
	}

	std::cout << this->month;
}

// Intent: To output the month abbreviation  corresponding with the month value
// Pre: nothing
// Post: print the called month
void Month::outputStr()
{
	int a = this->month;

	if (a == 1) {
		std::cout << "Jan";
	}
	if (a == 2) {
		std::cout << "Feb";
	}
	if (a == 3) {
		std::cout << "Mar";
	}
	if (a == 4) {
		std::cout << "Apr";
	}
	if (a == 5) {
		std::cout << "May";
	}
	if (a == 6) {
		std::cout << "Jun";
	}
	if (a == 7) {
		std::cout << "Jul";
	}
	if (a == 8) {
		std::cout << "Aug";
	}
	if (a == 9) {
		std::cout << "Sep";
	}
	if (a == 10) {
		std::cout << "Oct";
	}
	if (a == 11) {
		std::cout << "Nov";
	}
	if (a == 12) {
		std::cout << "Dec";
	}
}

// Intent: To create a new class nextMonth that is the current month + one month
// Pre: nothing
// Post: run the next month
Month Month::nextMonth()
{
	int nextMonth = this->month + 1;
	return nextMonth;
}
