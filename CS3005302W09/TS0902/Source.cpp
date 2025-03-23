/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/04/17
 * Editor: B11215002
 * Update Date: 2023/04/21
 * Description: This program tests functions used in the anonymous and Authenticate namespace
***********************************************************************/

#include <iostream>
#include "password.h"
#include "user.h"
using namespace std;
using namespace Authenticate;
int main() {
    inputUserName();
    inputPassword();
    cout << "Your username is " << getUserName() <<
        " and your password is: " <<
        getPassword() << endl;
    return 0;
}