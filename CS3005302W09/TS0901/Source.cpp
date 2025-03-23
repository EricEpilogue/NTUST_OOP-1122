/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/04/17
 * Editor: B11215002
 * Update Date: 2023/04/21
 * Description: This program tests functions used in the anonymous and Authenticate namespace
***********************************************************************/

#include <iostream>
#include <vector>
#include <string>

bool findExist(std::vector<std::string> v, std::string str1); //to find if str1 exists in v

int main() {
	std::string input;
	std::vector<std::string> inputList;

	while (!std::cin.eof()) {
		std::cin >> input;
		//set all to lowercase words
		for (int i = 0; i < input.length(); i++) {
			input[i] = tolower(input[i]);
		}
		inputList.push_back(input);
	}

	std::string longestWord = "";
	int longest = longestWord.length();

	for (auto& w : inputList) {
		//a word and it's reversed counter part
		std::string reversed = w;
		std::reverse(reversed.begin(), reversed.end());

		//update if both input word and it's reversed version exist yet not palindrome
		if (findExist(inputList, reversed) && w != reversed) {
			if (w.length() > longestWord.length()) {
				longestWord = w;
			}
		}
	}

	std::cout << longestWord;
}

// Intent: to find if str1 exists in vector v
// Pre: use argument v and str1
// Post: The function returns true or false
bool findExist(std::vector<std::string> v, std::string str1) {
	for (auto& w : v) {
		if (w == str1) {
			return true;
		}
	}

	return false;
}