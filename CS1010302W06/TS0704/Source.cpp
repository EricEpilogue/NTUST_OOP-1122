/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2023/03/28
 * Editor: B11215002
 * Update Date: 2023/03/29
 * Description: This program is to compute and output the Levenshtein Distance
***********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

int main(int argc, char *argv[]) {
	std::string str1;
	std::string str2;

	while (std::getline(std::cin, str1) && std::getline(std::cin, str2)) {
		size_t x = str1.length();
		size_t y = str2.length();

		if (x == 0) {
			std::cout << y << std::endl;
		}
		if (y == 0) {
			std::cout << x << std::endl;
		}

		//list input words into a 2D vector
		std::vector<std::vector<int>> vect(x + 1, std::vector<int>(y + 1, 0));

		for (int i = 0; i <= x; i++) {
			vect[i][0] = i;
		}
		for (int i = 0; i <= y; i++) {
			vect[0][i] = i;
		}

		//run the formula
		//(0,0) is a empty block not used in calculation
		for (size_t i = 1; i <= x; i++) {
			for (size_t j = 1; j <= y; j++) {
				//determine whether a change is needed or not
				if (str1[i - 1] == str2[j - 1]) {
					//no change
					vect[i][j] = vect[i - 1][j - 1];
				}
				else {
					//need to change
					//add value by 1 for each new iteration, and find the smallest value for the actions
					//vect[i][j - 1] is for insert
					//vect[i - 1][j] is for remove
					//vect[i - 1][j - 1] is for replace
					vect[i][j] = 1 + std::min(vect[i][j - 1], std::min(vect[i - 1][j], vect[i - 1][j - 1]));
				}
			}
		}

		std::cout << vect[x][y] << std::endl;
	}
}