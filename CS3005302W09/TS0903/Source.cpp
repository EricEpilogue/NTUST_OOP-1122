/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/04/21
 * Editor: B11215002
 * Update Date: 2024/04/21
 * Description: This program is to translate words with the given possible combinations
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>

bool translate(char first, char second, std::vector<std::pair<char, char>> translation);

int main() {
	int m = 0;
	int n = 0;

	while (true){
		std::vector<std::pair<char, char>> translation;
		std::cin >> m >> n;

		//the input to stop the program
		if (m == 0 && n == 0){
			return 0;
		}

		//initialize
		for (size_t i = 0; i < m; i++){
			std::pair<char, char> input;
			std::cin >> input.first >> input.second;
			translation.push_back(input);
		}

		for (size_t i = 0; i < n; i++){
			//initialize
			std::pair<std::string, std::string> words;
			std::cin >> words.first >> words.second;

			//length inequal, the translation we just be impossible
			if (words.first.length() != words.second.length()){
				std::cout << "no" << std::endl;
				continue;
			}
			//return true if it's already the same
			else if (words.first == words.second){
				std::cout << "yes" << std::endl;
				continue;
			}

			bool flag = true;

			for (size_t i = 0; i < words.first.length(); i++){
				//run the function to see whether it's possible
				if (!translate(words.first[i], words.second[i], translation)){
					//can't
					flag = false;
					std::cout << "no" << std::endl;
					break;
				}
				else {
					//can
					flag = true;
				}
			}

			if (flag == true){
				std::cout << "yes" << std::endl;
			}
		}

		//clear and reset the translation vector for next iteration
		translation.clear();
	}
}

// Intent: To translate the alphabets from the first word to the second
// Pre: we get alphabets from each word as well as the list of possible translations
// Post: The function returns true or false.
bool translate(char from, char to, std::vector<std::pair<char, char>> translation) {
	std::vector<char> alphabets; //1
	std::vector<char> visited; //2

	//alphabet from first word
	alphabets.push_back(from);
	visited.push_back(from);

	while (!alphabets.empty()) {
		//value of the latest character inserted
		char current = alphabets.back();

		//clears the temporate use
		alphabets.pop_back();

		if (current == to) {
			return true;
		}

		for (const auto& pair : translation) {
			//if first letter match the first list AND the second letter hasn't been used yet
			if (pair.first == current && std::find(visited.begin(), visited.end(), pair.second) == visited.end()) {
				//we translate the first alphabet into the second by this
				alphabets.push_back(pair.second);
				//stops the infinite loop
				visited.push_back(pair.second);
			}
		}
	}

	return false;
}

/*
bool translate(char from, char to, std::vector<std::pair<char, char>> translate){
	std::vector<char> alphabets;
	std::vector<char> visited;
	alphabets.push_back(from);
	visited.push_back(from);

	while (!alphabets.empty()) {
		char current = alphabets.back();
		alphabets.pop_back();

		if (current == to) {
			return true;
		}
		
	//error one
		for (auto& it : translate) {
			//error two
			if (it.first == current && std::find(visited.begin(), visited.end(), it.second) == visited.end()) {
				alphabets.push_back(it.second);
				visited.push_back(it.second);
			}
		}

	}

	return false;
}
*/