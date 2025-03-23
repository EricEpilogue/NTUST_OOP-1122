/***********************************************************************
 * File: Form.cpp
 * Author: B11215002
 * Create Date: 2024/03/28
 * Editor: B11215002
 * Update Date: 2024/03/29
 * Description: This program is to store the functions used in class Form
***********************************************************************/
#include "Form.h"

// Intent: To update the variable answer with the input string
// Pre: default constructor
// Post: now answer is what you input into the main function
void Form::SetInputWord(std::string inputWord) {
	this->answer = inputWord; //e.g: SWIMMING
}

// Intent: To update the answer to lower cases
// Pre: SWIMMING
// Post: swimming
void Form::ProcessInputWord() {
	//should make it:swimming
	for (int i = 0; i < answer.length(); i++) {
		answer[i] = tolower(answer[i]);
	}
}

// Intent: To update the file name that stores the correct 
// Pre: SWIMMING
// Post: swimming
void Form::SetFileName(std::string fileName) {
	this->file = fileName; //words.txt
}

// Intent: To store every matching word into the output vector for printing
// Pre: alphabets from the input word
// Post: a vector full of matching words
void Form::Load_CompareWord() {
	std::vector<char> alphabets;

	//get all the characters in the given word
	for (char ch : this->answer) {
		alphabets.push_back(ch);
	}

	//open file
	std::ifstream FILE;
	FILE.open(this->file);

	//search and sort words
	while (FILE >> this->words) {
		std::string temp;
		temp = words;

		//look for matches, if any alphabet matches, make it '1'
		for (int i = 0; i < alphabets.size(); i++) {
			for (int j = 0; j < temp.length(); j++) {
				if (temp[j] == alphabets[i]) {
					temp[j] = '1';
					break;
				}
				else {
					continue;
				}
			}
		}

		int determine = 0;

		//if a copy of word is full of '1's, it is matching and valid
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] != '1') {
				determine = 1;
			}
		}

		//store it into the vector matches if it is valid
		if (determine == 0) {
			matches.push_back(words);
		}
	}
}

// Intent: To print every matching word from the vector matches
// Pre: nothing
// Post: cout all the words in a new line
void Form::PrintFoundWords() {
	for (int i = 0; i < matches.size(); i++) {
		std::cout << matches[i] << std::endl;
	}
}