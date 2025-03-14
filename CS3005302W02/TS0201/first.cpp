#include <iostream>
#include <math.h>
double avg(double array[], int size);
double stdDeviation(double average, double array[], int size);

int main(int argc, char** argv) {
	double input = 0;
	double numbers[100] = {0};
	int size = 0;
	long int iterations = 0;
	std::cin >> iterations;

	while (!std::cin.eof()) {
		for (int i = 0; i < iterations; i++) {
			std::cin >> input;
			numbers[size++] = input;
		}

		double average = avg(numbers, size);
		double devi = stdDeviation(average, numbers, size);

		std::cout << "Average:" << average << "\tStandard deviation:" << devi << std::endl;

		for (int i = 0; i < size; i++) {
			numbers[i] = 0;
		}

		size = 0;
		iterations = 0;
		std::cin >> iterations;
	}
	return 0;
	
}

double avg(double array[], int size) {
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}

	sum /= size;
	return sum;
}

double stdDeviation(double average, double array[], int size) {
	double output = 0.0;

	for (int i = 0; i < size ; i++) {
		output += pow((array[i] - average),2);
	}
	
	output = abs(output);
	output /= size;
	output = sqrt(output);
	
	return output;
}