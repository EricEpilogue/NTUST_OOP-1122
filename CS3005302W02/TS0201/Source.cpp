#include <iostream>

long double avg(int array[], int size);
long double stdDeviation(int array[], int size);

int main(int argc, char** argv) {
	int input = 0;
	int numbers[200];
	int size = 0;

	while (!std::cin.eof()) {
		std::cin >> input;
		numbers[size++] = input;
	}

	long double average = avg(numbers, size);
	long double deviation = stdDeviation(numbers, size);

	std::cout << "Average:" << average << std::endl;
	std::cout << "Standard deviaton" << deviation << std::endl;
	return 0;
}

long double avg(int array[], int size) {
	int sum = 0;
	long double sum = 0.0;

	for (int i = 0; i < size; i++) {
		sum += array[i];
	}

	sum /= size;
	return sum;
}

long double stdDeviation(int array[], int size) {
	long double average = avg(array, size);
	long double output = 0.0;

	for (int i = 0; i < size; i++) {
		output += array[i] - average;
	}

	output /= size;
	return output;
}