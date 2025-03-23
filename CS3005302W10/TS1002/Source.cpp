/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/4/29
 * Editor: B11215002
 * Update Date: 2024/4/29
 * Description: This program is to recursively find matching words with a given board
***********************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#define SIZE 5

//add for recursive next steps for 8 different direction
const int direction[8][8] = { { 1,0 },{ 1,1 },{ 0,1 },{ -1,1 },{ -1,0 },{ -1,-1 },{ 0,-1 },{ 1,-1 } };
//size + 1 to reserve space for \0
char wordBoard[SIZE + 1][SIZE + 1];
//this is a temp array to determine a path has been accessed or not
int board[SIZE][SIZE] = { 0 };

void resetBoard();
bool isValid(int x, int y, std::string from, std::string target);
bool wordSearch(std::string findWord);

int main() {
	while (std::cin >> wordBoard[0]) {
		//get input to global variable wordBoard
		for (int i = 1; i < SIZE; i++) {
			std::cin >> wordBoard[i];
		}

		std::string inputStr;
		std::fstream fs;
		fs.open("words.txt");

		//run comparison
		while (std::getline(fs, inputStr)) {
			if (wordSearch(inputStr)) {
				std::cout << inputStr << std::endl;
			}
		}

		fs.close();
	}

	return 0;
}

// Intent: To reset the board to default condition
// Pre: board has the recording of the moving steps of previous word comparison
// Post: now it's back to 0
void resetBoard() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = 0;
		}
	}
}

// Intent: To judge the starting location and call recursive function
// Pre: with a word to search, this function loops through the 2D char array and form all matches
// Post: if true, print the word in main function
bool wordSearch(std::string word) {
	for (int startX = 0; startX < SIZE; startX++) {
		for (int startY = 0; startY < SIZE; startY++) {
			resetBoard();
			if (isValid(startX, startY, "", word)) {
				return true;
			}
		}
	}
	return false;
}

// Intent: Recursively check letter by letter to determine whether words are the same
// Pre: x,y as coordinates, a string and a word to find
// Post: 
bool isValid(int x, int y, std::string from, std::string target) {
	//out of range or already accessed
	if (board[x][y] == 1 || x == SIZE || x < 0 || y == SIZE || y < 0) {
		return false;
	}
	else {
		board[x][y] = 1;

		from.push_back(wordBoard[x][y]);

		if (from == target) {
			return true;
		}
		else if (target[from.size() - 1] != wordBoard[x][y]) {
			board[x][y] = 0;
			return false;
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (isValid(x + direction[i][0], y + direction[i][1], from, target)) {
					return true;
				}
			}
		}
	}
	board[x][y] = 0;
	return false;
}

