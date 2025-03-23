/***********************************************************************
 * File: main.cpp
 * Author: B11215002
 * Create Date: 2024/4/12
 * Editor: B11215002
 * Update Date: 2024/4/12
 * Description: This program is to test the PrimeNumber.h file, will be replaced in OJ
***********************************************************************/

#include "PrimeNumber.h"
#include <iostream>

using namespace std;

int main()
{	
	PrimeNumber p1, p2(13);	
	PrimeNumber a = ++p1;
	PrimeNumber b = p2++;
	cout << a.get() << endl; //2
	cout << p1.get() << endl; //2
	cout << b.get() << endl; //13
	cout << p2.get() << endl; //17
	return 0;
}
