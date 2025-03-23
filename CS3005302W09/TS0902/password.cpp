/***********************************************************************
 * File: password.cpp
 * Author: B11215002
 * Create Date: 2024/04/17
 * Editor: B11215002
 * Update Date: 2023/04/21
 * Description: This program set functions used in the anonymous and Authenticate namespace
***********************************************************************/
#include <iostream>
#include <string>
#include "password.h"
using namespace std;

//anonymous namespace
namespace
{
    string password;

    // Intent: To check whether password matches the requirements or not
    // Pre: enter the string password
    // Post: The function returns true or false
    bool isValid() {
        if (password.length() >= 8) {
            for (auto& ch : password) {
                //check for non alphabets
                if (!isalpha(ch)) {
                    return true;
                }
            }
            return false;
        }
        else
            return false;
    }
}

//For Authenticate namespace
// Intent: insert password
// Pre: enter the string password
// Post: The function gets password
void Authenticate::inputPassword() {
    do {
        cout << "Enter your password (at least 8 characters " <<
            "and at least one non-letter)" << endl;
        cin >> password;
    } while (!isValid());
}

// Intent: The function returns password
string Authenticate::getPassword() {
    return password;
}