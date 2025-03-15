/***********************************************************************
 * File: Month.h
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to set function prototypes
***********************************************************************/

#pragma once
class Month
{
private:
	int month = 0;
public:
	Month(); //default constructor
	Month(char first, char second, char third); //default constructor with char input
	Month(int monthInt); //default constructor with int input
	~Month(); //copy
	void inputInt(); //get int and convert it into month abbreviation 
	void inputStr(); //get abbreviation of a month and get the correct month value
	void outputInt(); //output the month
	void outputStr(); //output the month abbreviation 
	Month nextMonth();
};

