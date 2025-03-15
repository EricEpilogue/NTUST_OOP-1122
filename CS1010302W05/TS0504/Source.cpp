/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to make sure each 3x3 square contains each number from 1-9 exactly once, and there are no duplicates. 
***********************************************************************/
#include <iostream>
#include <ctype.h>
#include <string>

void bubbleSort(int arr[], int n); //to sort numbers from each 3x3 square ascendingly

int main(int argc, char** argv) {
	int sudoku[81] = { 0 };
	char input;

	//read until EOF
	while (true) {
		for (int i = 0; i < 81; i++) {
			input =	getchar();
			if (input == EOF) {
				return 0;
			}
			if (!isdigit(input)) {
				i -= 1;
				continue;
			}
			else {
				//to convert char input into int data type
				sudoku[i] = input - '0';
			}
		}

		int temp[9] = { 0 };
		int count = 0;
		int determine = 0;
		int start = 0;

		for (int m = 0; m < 9; m++) {
			//pick the starting location, indexs are 0 1 2/27 30 33/54 57 60
			count = 0;
			if (m < 3) {
				start = 3*m;
			}
			else if (m >= 3 && m < 6) {
				start = 3 * (9 + (m - 3));
			}
			else if (m >= 6 && m < 9) {
				start = 3 * (18 + (m - 6));
			}
			
			//fill the 3x3 into a 1D array
			for (int k = 0; k < 3; k++) {
				temp[count++] = sudoku[start++];
			}

			start += 6;
			for (int k = 0; k < 3; k++) {
				temp[count++] = sudoku[start++];
			}

			start += 6;
			for (int k = 0; k < 3; k++) {
				temp[count++] = sudoku[start++];
			}

			//check if 1~9 are in the box without duplicates
			if (determine == 0) {
				for (int i = 0; i < 9; i++) {
					bubbleSort(temp, 9);
					if (temp[i] != i + 1) {
						std::cout << "False" << std::endl;
						determine = 1;
						break;
					}
				}
			}
			else {
				break;
			}
		}

		if (determine == 0) {
			std::cout << "True" << std::endl;
		}
	}
}

// Intent: function to sort integers ascendingly
// Pre: The array is unsorted
// Post: The array is now sorted
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}

		// If no two elements were swapped, break the function
		if (swapped == false)
			break;
	}
}