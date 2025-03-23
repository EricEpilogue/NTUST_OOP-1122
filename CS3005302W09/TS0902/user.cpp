/***********************************************************************
 * File: user.cpp
 * Author: B11215002
 * Create Date: 2024/04/17
 * Editor: B11215002
 * Update Date: 2023/04/21
 * Description: This program set functions used in the anonymous and Authenticate namespace
***********************************************************************/

#include <iostream>
#include <string>
#include "user.h"
using namespace std;

//anonymous namespace
namespace
{
	string username;

	// Intent: To check whether username matches the requirements or not
	// Pre: enter the string username
	// Post: The function returns true or false
	bool isValid() {
		if (username.length() == 8){
			for (auto& ch : username) {
				if (!isalpha(ch)) {
					return false;
				}
			}
			return true;
		}

		return false;
	}
}

//For Authenticate namespace
// Intent: insert username
// Pre: enter the string username
// Post: The function gets username
void Authenticate::inputUserName() {
	do {
		cout << "Enter your username (8 letters only)" << endl;
		cin >> username;
	} while (!isValid());
}

// Intent: The function returns username
string Authenticate::getUserName() {
	return username;
}