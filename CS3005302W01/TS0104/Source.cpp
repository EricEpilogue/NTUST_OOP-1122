/***********************************************************************
 * File: Main.cpp
 * Author: B11215002
 * Create Date: 2024/02/22
 * Editor: B11215002
 * Update Date: 2024/02/22
 * Description: This program is to take an arbitrary integer INPUT ( INPUT ) and satisfy the output according to the requirements.
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char** argv) {

	//initialize and take input
	std::string input;
	std::cin >> input;

	//determine and line the input up
	while (!std::cin.eof()) {
		if (input.length() <= 10) {
			for (int i = 0; i < 10 - input.length(); i++) {
				std::cout << " ";
			}
			std::cout << input << std::endl;
		}
		else {
			std::cout << input << std::endl;
		}
		std::cin >> input;
	}
	
	return 0;
}