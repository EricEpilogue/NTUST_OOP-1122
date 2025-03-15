/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2023/03/28
 * Editor: B11215002
 * Update Date: 2023/03/29
 * Description: This program is to compute and output the way cow calculates
***********************************************************************/
#include<iostream>
#include<string>
#include<vector>

std::string doA(std::string num1, std::string num2); //function to do the A symbol
std::string doR(std::string num2);//function to do the R symbol
std::string doL(std::string num2);//function to do the L symbol
void doN();//function to do the N symbol

int main(int argc, char* argv[]) {
	int N = 0;
	std::string num1;
	std::string num2;
	std::vector<char> operation;
	char input;
	std::string answer;

	while (std::cin >> N) {
		//N * 6 lines
		std::cout << "COWCULATIONS OUTPUT" << std::endl;

		for (int i = 0; i < N; i++) {
			std::cin >> num1;
			std::cin >> num2;

			//make sure inputs are all in uppercases
			for (int j = 0; j < 3; j++) {
				std::cin >> input;
				input = toupper(input);
				operation.push_back(input);
			}

			std::cin >> answer;

			//get punctuation for calculation
			for (int j = 0; j < 3; j++) {
				if (operation[j] == 'A') {
					num2 = doA(num1, num2);
				}
				else if (operation[j] == 'R') {
					num2 = doR(num2);
				}
				else if (operation[j] == 'L') {
					num2 = doL(num2);
				}
				else if (operation[j] == 'N') {
					num2 = num2;
				}
			}

			//padded with V's on the left 
			if (num2.length() < 8) {
				for (int k = 0; k <= (9 - num2.length()); k++) {
					num2.insert(0, "V");
				}
			}
			//avoid output being too long, erase the extra parts on the left
			if (num2.length() > 8) {
				num2.erase(0, 1);
			}


			if (num2 == answer) {
				std::cout << "YES" << std::endl;
			}
			else {
				std::cout << "NO" << std::endl;
			}

			if (i == N - 1) {
				std::cout << "END OF OUTPUT" << std::endl;
			}
			//clear the input vector that stored all the symbols for calculation
			operation.clear();
		}
	}

	return 0;
}

// Intent: To calculate the using A operation
// Pre: 2 string inputs
// Post: The function returns the result
std::string doA(std::string str1, std::string str2) {
	//initialize
	std::string num1 = str1;
	std::string num2 = str2;
	std::string newNum2;
	int sum = 0;
	int a = str1.length();
	int b = str2.length();

	// Fill ' ' character to the shorter string to line two strings up
	int diff = b - a;
	if (diff > 0) {
		for (int k = 0; k < diff; k++) {
			num1.insert(num1.begin(), ' ');
		}
	}
	else if (diff < 0) {
		diff *= -1;
		for (int k = 0; k < diff; k++) {
			num2.insert(num2.begin(), ' ');
		}
	}
	
	a = num1.length();
	b = num2.length();

	//using the concept of table and array to do the calculation
	bool carry = false;
	for (int i = 0; i < a; i++) {
		if (num1[i] == 'V') {
			num1[i] = 0;
		} 
		else if (num1[i] == 'U') {
			num1[i] = 1;
		}
		else if (num1[i] == 'C') {
			num1[i] = 2;
		}
		else if (num1[i] == 'D') {
			num1[i] = 3;
		}
		else {
			num1[i] = 0;
		}
	}

	for (int i = 0; i < b; i++) {
		if (num2[i] == 'V') {
			num2[i] = 0;
		}
		else if (num2[i] == 'U') {
			num2[i] = 1;
		}
		else if (num2[i] == 'C') {
			num2[i] = 2;
		}
		else if (num2[i] == 'D') {
			num2[i] = 3;
		}
		else {
			num2[i] = 0;
		}
	}

	//calculation process
	while (a > 0) {
		a--;
		b--;
		//addiction for two corresponding vectors
		sum = num1[a] + num2[b];
		switch (sum) {
		case 0:
			//V
			if (carry == true) {
				//V A U = U
				newNum2.insert(newNum2.begin(), 'U');
				carry = false;
			}
			else {
				newNum2.insert(newNum2.begin(), 'V');
				carry = false;
			}
			break;
		case 1:
			//U
			if (carry == true) {
				//U A U = C
				newNum2.insert(newNum2.begin(), 'C');
				carry = false;
			}
			else {
				newNum2.insert(newNum2.begin(), 'U');
				carry = false;
			}
			break;
		case 2:
			//C
			if (carry == true) {
				//C A U = D
				newNum2.insert(newNum2.begin(), 'D');
				carry = false;
			}
			else {
				newNum2.insert(newNum2.begin(), 'C');
				carry = false;
			}
			break;
		case 3:
			//D
			if (carry == true) {
				//D A U = VU
				if (b == 0) {
					newNum2.insert(newNum2.begin(), 'V');
					newNum2.insert(newNum2.begin(), 'U');
				}
				else {
					newNum2.insert(newNum2.begin(), 'V');
					carry = true;
				}
			}
			else {
				newNum2.insert(newNum2.begin(), 'D');
				carry = false;
			}
			break;
		case 4:
			//VU, carry over = yes
			if (carry == true) {
				//V A U = U
				if (b == 0) {
					newNum2.insert(newNum2.begin(), 'U');
					newNum2.insert(newNum2.begin(), 'U');
				}
				else {
					newNum2.insert(newNum2.begin(), 'U');
					carry = true;
				}
			}
			else {
				if (b == 0) {
					newNum2.insert(newNum2.begin(), 'V');
					newNum2.insert(newNum2.begin(), 'U');
				}
				else {
					newNum2.insert(newNum2.begin(), 'V');
					carry = true;
				}
			}
			break;
		case 5:
			//UU, carry over = yes
			if (carry == true) {
				//U A U = C
				if (b == 0) {
					newNum2.insert(newNum2.begin(), 'C');
					newNum2.insert(newNum2.begin(), 'U');
				}
				else {
					newNum2.insert(newNum2.begin(), 'C');
					carry = true;
				}
			}
			else {
				if (b == 0) {
					newNum2.insert(newNum2.begin(), 'U');
					newNum2.insert(newNum2.begin(), 'U');
				}
				else {
					newNum2.insert(newNum2.begin(), 'U');
					carry = true;
				}
			}
			break;
		case 6:
			//CU, carry over = yes
			if (carry == true) {
				//C A U = D
				if (b == 0) {
					newNum2.insert(newNum2.begin(), 'D');
					newNum2.insert(newNum2.begin(), 'U');
				}
				else {
					newNum2.insert(newNum2.begin(), 'D');
					carry = true;
				}
			}
			else {
				if (b == 0) {
					newNum2.insert(newNum2.begin(), 'C');
					newNum2.insert(newNum2.begin(), 'U');
				}
				else {
					newNum2.insert(newNum2.begin(), 'C');
					carry = true;
				}
			}
			break;
		}
	}

	return newNum2;
}

// Intent: To calculate the using R operation
// Pre: 2 string inputs
// Post: The function returns the result
std::string doR(std::string num2) {
	num2.insert(0, "V");
	num2.erase(num2.end() - 1);
	return num2;
}

// Intent: To calculate the using V operation
// Pre: 2 string inputs
// Post: The function returns the result
std::string doL(std::string num2) {
	num2.insert(num2.length (), "V");
	return num2;
}

// Intent: To calculate the using N operation
// Pre: 2 string inputs
// Post: The function return nothing as it is the NULL operation
void doN() {
	//NULL
}