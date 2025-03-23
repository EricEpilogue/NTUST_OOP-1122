/***********************************************************************
 * File: main.cpp
 * Author: B11215002
 * Create Date: 2024/5/15
 * Editor: B11215002
 * Update Date: 2024/5/20
 * Description: This program is to test the convert of absolute value implemented in Template.h
***********************************************************************/

#include "Template.h"
#include <iostream>
using namespace std;

int main()
{
	int i1, i2;
	double d1, d2;
	char c1, c2;
	i1 = 10; i2 = 20;
	cout << "Absolute value of 10 - 20 is " << absoluteValue(i1, i2) << endl;

	d1 = 5.5; d2 = 3.1;
	cout << "Absolute value of 5.5 - 3.1 is " << absoluteValue(d1, d2) << endl;

	c1 = 'A', c2 = 'C';
	cout << "Absolute value of A - C is " << absoluteValue(c1, c2) << endl;
	return 0;
}