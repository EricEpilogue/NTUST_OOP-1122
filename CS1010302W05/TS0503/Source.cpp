/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to keep records of at most 10 student data by structures
***********************************************************************/

#include "Student.h"
#include <iostream>
#include <string>

Student stu;

int main(int argc, char** argv) {
	std::string command;

	//get input until EOF
	while (std::cin >> command) {
		//convert command input into lower case for determination 
		for (char& c : command) {
			c = std::tolower(c);
		}

		if (command == "print") {
			stu.print();
		}
		else if (command == "delete") {
			stu.deleteo();
		}
		else if (command == "insert") {
			stu.insert();
		}
		else if (command == "search") {
			stu.search();
		}
		else {
			std::cout << "Input Error\n";
		}
	}

	return 0;
}