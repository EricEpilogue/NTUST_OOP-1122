#include <iostream>
#include <string>
#include <math.h>

int main(int argc, char **argv) {

	std::string input;
	//std::cout << input << "||";

	while (std::cin >> input) {
		long int length = 0;
		length = input.length();
		long int width = 0;

		for (width = 0; width < 1000; width++) {
			if (pow(width - 1, 2) < length) {
				if (pow(width, 2) >= length) {
					break;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}

		char output[100][100] = {};
		long int inputSize = 0;

		for (long int i = 0; i < width +1 ; i++) {
			for (long int j = 0; j < width; j++) {
				output[j][i] = input[inputSize++];
				if (inputSize > length) {
					output[j][i] = '\0';
					break;
				}
			}
			if (inputSize > length) {
				break;
			}
		}

		//print the square, but rows first then columns
		for (long int i = 0; i < width; i++) {
			/*for (long int j = 0; j < width; j++) {
				std::cout << output[i][j];
				std::cout << output[i];
			}
			if(i != width -1)
				std::cout << std::endl;
				*/
			std::cout << output[i] << std::endl;
		}
	}
}