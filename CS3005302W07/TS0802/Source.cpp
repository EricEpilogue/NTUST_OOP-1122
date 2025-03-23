/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/4/4
 * Editor: B11215002
 * Update Date: 2024/4/8
 * Description: this program is to do matrix multiplication
***********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

int main() {
	int m, n, k, p;
	std::cin >> m >> n >> k >> p;
	//check if first matrix's column count is equal to the second matrix's row count
	if (n != k) {
		std::cout << "Matrix multiplication failed." << std::endl;
		return 0;
	}

	//enter the first matrix, m = row, n = column
	std::vector<std::vector<double>> Matrix1(m, std::vector<double>(n, 0.0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> Matrix1[i][j];
		}
	}

	//enter the second matrix, k = row, p = column
	std::vector<std::vector<double>> Matrix2(k, std::vector<double>(p, 0.0));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < p; j++) {
			std::cin >> Matrix2[i][j];
		}
	}

	//do the multiplication
	std::vector<std::vector<double>> result(m, std::vector<double>(p, 0.0));
	//first matrix's row
	for (int i = 0; i < m; i++) {
		//second matrix's column
		for (int j = 0; j < p; j++) {
			//first's column and second's row
			for (int k = 0; k < n; k++) {
				result[i][j] += Matrix1[i][k] * Matrix2[k][j];
			}
		}
	}

	//print the result
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			std::cout << result[i][j];
			if (j != p - 1) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	return 0;
}