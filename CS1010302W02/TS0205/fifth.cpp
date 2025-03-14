#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string addLargeNumbers(std::string str1, std::string str2);

int main() {
	int iterations = 0;
	std::string num1 = "";
	std::string num2 = "0";
	std::string output;
	std::cin >> iterations;
	for (int i = 0; i < iterations; i++) {	
		std::cin >> num1;
		std::cin >> num2;
		output = addLargeNumbers(num1, num2);
		std::cout << output << std::endl;
		num1 = "0";
		num2 = "0";
		//std::cout << output << "/";
	}
	return 0;
}

std::string addLargeNumbers(std::string str1, std::string str2) {

	std::string output;
	int leftover = 0;
	int length = std::max(str1.length(), str2.length());
	str1 = std::string(length - str1.length(), '0') + str1;
	str2 = std::string(length - str2.length(), '0') + str2;

	for (int i = length - 1; i >= 0; i--) {
		if (std::isdigit(str1[i]) == false) {
			std::string error = "Not a valid number, please try again.";
			return error;
		}
		if (std::isdigit(str2[i]) == false) {
			std::string error = "Not a valid number, please try again.";
			return error;
		}
		int digit1 = str1[i] - '0';
		int digit2 = str2[i] - '0';
		int sum = digit1 + digit2 + leftover;
		leftover = sum / 10;
		output.push_back((sum % 10) + '0');
	}

	if (leftover != 0)
		output.push_back(leftover + '0');

	std::reverse(output.begin(), output.end());

	return output;
}