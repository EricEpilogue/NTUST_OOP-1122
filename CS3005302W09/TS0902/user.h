/***********************************************************************
 * File: user.cpp
 * Author: B11215002
 * Create Date: 2024/04/17
 * Editor: B11215002
 * Update Date: 2023/04/21
 * Description: This program set prototypes
***********************************************************************/
#pragma once
#include <iostream>
#include <string>

namespace {
	extern std::string username; //set as extern variables for use in cpp files
	bool isVaild(); //to check for meeting requirements
}

namespace Authenticate {
	void inputUserName(); //store username
	std::string getUserName(); //return username
}