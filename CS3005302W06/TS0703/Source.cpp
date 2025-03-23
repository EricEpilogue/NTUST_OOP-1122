/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/03/28
 * Editor: B11215002
 * Update Date: 2024/03/29
 * Description: This program is to display integers like how seven segments display works
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

void sevenSegmentDisplay(std::string input);//to transform the string input into seven segment display

int main() {
	std::string input;
	
	//get input
	while (std::getline(std::cin, input)) {

		for (int i = 0; i < input.length(); i++) {
			//check and ignore everything that's not a number
			if (!isdigit(input[i]) || isalpha(input[i]) || ispunct(input[i]) || input[i] == ' ') {
				input.erase(input.begin() + i);
			}
		}
		sevenSegmentDisplay(input);
	}
}

// Intent: To turn the input string into seven segment display
// Pre: Input the validate string 
// Post: The function prints the number out
void sevenSegmentDisplay(std::string input) {
	//initialize
	std::vector<char> firstRow;
	std::vector<char> secondRow;
	std::vector<char> thirdRow;
	char emptySpace = ' ';
	char verticalLine = '|';
	char horizontalLine = '_';

	//design pattern for every number, 3 rows for each number
	for (int i = 0; i < input.length(); i++) {
		switch (input[i]) {
		case '1':
			firstRow.push_back(emptySpace);
			firstRow.push_back(emptySpace);
			firstRow.push_back(emptySpace);

			secondRow.push_back(emptySpace);
			secondRow.push_back(emptySpace);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(emptySpace);
			thirdRow.push_back(emptySpace);
			thirdRow.push_back(verticalLine);
			break;
		case '2':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(emptySpace);
			secondRow.push_back(horizontalLine);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(verticalLine);
			thirdRow.push_back(horizontalLine);
			thirdRow.push_back(emptySpace);
			break;
		case '3':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(emptySpace);
			secondRow.push_back(horizontalLine);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(emptySpace);
			thirdRow.push_back(horizontalLine);
			thirdRow.push_back(verticalLine);
			break;
		case '4':
			firstRow.push_back(emptySpace);
			firstRow.push_back(emptySpace);
			firstRow.push_back(emptySpace);

			secondRow.push_back(verticalLine);
			secondRow.push_back(horizontalLine);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(emptySpace);
			thirdRow.push_back(emptySpace);
			thirdRow.push_back(verticalLine);
			break;
		case '5':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(verticalLine);
			secondRow.push_back(horizontalLine);
			secondRow.push_back(emptySpace);

			thirdRow.push_back(emptySpace);
			thirdRow.push_back(horizontalLine);
			thirdRow.push_back(verticalLine);
			break;
		case '6':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(verticalLine);
			secondRow.push_back(horizontalLine);
			secondRow.push_back(emptySpace);

			thirdRow.push_back(verticalLine);
			thirdRow.push_back(horizontalLine);
			thirdRow.push_back(verticalLine);
			break;
		case '7':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(emptySpace);
			secondRow.push_back(emptySpace);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(emptySpace);
			thirdRow.push_back(emptySpace);
			thirdRow.push_back(verticalLine);
			break;
		case '8':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(verticalLine);
			secondRow.push_back(horizontalLine);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(verticalLine);
			thirdRow.push_back(horizontalLine);
			thirdRow.push_back(verticalLine);
			break;
		case '9':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(verticalLine);
			secondRow.push_back(horizontalLine);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(emptySpace);
			thirdRow.push_back(horizontalLine);
			thirdRow.push_back(verticalLine);
			break;
		case '0':
			firstRow.push_back(emptySpace);
			firstRow.push_back(horizontalLine);
			firstRow.push_back(emptySpace);

			secondRow.push_back(verticalLine);
			secondRow.push_back(emptySpace);
			secondRow.push_back(verticalLine);

			thirdRow.push_back(verticalLine);
			thirdRow.push_back(horizontalLine);
			thirdRow.push_back(verticalLine);
			break;
		}
	}

	//print out row by row
	for (int i = 0; i < firstRow.size(); i++) {
		std::cout << firstRow[i];
	}

	std::cout << "\n";

	//second row
	for (int i = 0; i < secondRow.size(); i++) {
		std::cout << secondRow[i];
	}

	std::cout << "\n";

	//third row
	for (int i = 0; i < thirdRow.size(); i++) {
		std::cout << thirdRow[i];
	}

	std::cout << "\n";
}