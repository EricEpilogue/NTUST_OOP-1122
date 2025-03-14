/***********************************************************************
 * File: Main.cpp
 * Author: B11215002
 * Create Date: 2024/02/22
 * Editor: B11215002
 * Update Date: 2024/02/22
 * Description: This program is to take seconds as input and print it in a hour/minute/second format.
***********************************************************************/

#include <iostream>

int main(int argc, char** argv) {

	//initialize
	unsigned long long int input = 0;
	unsigned long long int hours = 0;
	unsigned long long int minutes = 0;
	unsigned long long int seconds = 0;

	//receive input as seconds
	std::cin >> input;

	while (!std::cin.eof()) {
		seconds = input % 60;
		minutes = (input - seconds) / 60;
		hours = (minutes - (minutes % 60)) / 60;
		minutes %= 60;
		std::cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds" << std::endl;
		std::cin >> input;
	}
}