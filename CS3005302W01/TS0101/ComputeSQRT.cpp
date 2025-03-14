/***********************************************************************
 * File: Main.cpp
 * Author: B11215002
 * Create Date: 2024/02/22
 * Editor: B11215002
 * Update Date: 2024/02/22
 * Description: This program is to use the Babylonian algorithm to compute the square root of a positive number n.
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream> 

int main(int argc, char** argv) {

	//input
	double n = 0.0;
	//answer
	double guess;
	//equals to n/guess
	double r;
	//initialize the previous guess
	double previousGuess = 0.0;

	//input
	std::cin >> n;
	guess = n / 2;

	//loop while file inputs numbers
	while(!std::cin.eof()){

		//calculate
		while (abs(guess - previousGuess) > 0.01) {
			previousGuess = guess;
			r = n / guess;
			guess = (guess + r) / 2;
		}

		//output the results
		printf("%.2f\n", guess);

		//reset
		guess = 0.0;
		r = 0.0;
		n = 0.0;
		previousGuess = 0.0;
		std::cin >> n;
		guess = n / 2;
	}

	//close files
	return 0;
}
