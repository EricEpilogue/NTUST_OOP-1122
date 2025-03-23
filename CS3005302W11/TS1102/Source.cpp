/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/4/30
 * Editor: B11215002
 * Update Date: 2024/5/4
 * Description: This program is to compute matrix multiplication
***********************************************************************/

#include <iostream>
#include <vector>
#include <math.h>

int main() {
	int col1, row1;
	int col2, row2;

	//read input until eof
	while (std::cin >> col1 >> row1 >> col2 >> row2) {
		if (row1 != col2) {
			std::cout << "Matrix multiplication failed.";
			break;
		}

		//get input and initialize first matrix
		std::vector<std::vector<int>> matrix1(col1, std::vector<int>(row1));	
		for (int i = 0; i < col1; i++) {
			for (int j = 0; j < row1; j++) {
				std::cin >> matrix1[i][j];
			}
		}

		//get input and initialize second matrix
		std::vector<std::vector<int>> matrix2(col2, std::vector<int>(row2));
		for (int i = 0; i < col2; i++) {
			for (int j = 0; j < row2; j++) {
				std::cin >> matrix2[i][j];
			}
		}

		//calculate the result
		std::vector<std::vector<int>> result(col1, std::vector<int>(row2));
		//loop through the first matrix's row
		for (int i = 0; i < col1; i++) {
			//loop through the second matrix's column
			for (int j = 0; j < row2; j++) {
				for (int k = 0; k < row1; k++) {
					result[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}

		//print the result as required
		for (int i = 0; i < col1; i++) {
			for (int j = 0; j < row2; j++) {
				if (j == row2 - 1)
					std::cout << result[i][j];
				else
					std::cout << result[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	return 0;
}