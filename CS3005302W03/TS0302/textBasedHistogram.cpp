#include <iostream>
#include <fstream>
#include <string>

const int SIZE = 200;

void selection_sort(int array[], int count);

int main(int argc, char** argv) {
	int grades[SIZE] = { 0 };
	int input = 0;
	int count = 0;
	std::ifstream file;
	file.open("grade.txt");

	while (file >> input) {
		grades[count++] = input;
	}

	file.close();

	selection_sort(grades, count);

	int temp = 0;
	int numCount = 0;
	int determine = 0;
	int appeared = 0;
	int outputList[SIZE] = { 0 };
	std::ofstream outfile("grades.Output");

	while (determine == 0) {
		for (int i = 0; i < count; i++) {
			int previous = temp;
			temp = grades[i];
			outputList[i] = temp;
	
			for (int j = 0; j < count; j++) {
				if (temp == grades[j])
					numCount++;
				//std::cout << numCount << std::endl;
			}
			for (int k = 0; k < i; k++) {
				if (grades[i] == outputList[k]) {
					appeared = 1;
				}
			}

			if (appeared == 0 && i != count - 1) {
				//std::cout << numCount << " grade(s) of " << temp << std::endl;
				if (temp != previous + 1 && temp != 0) {
					outfile << "0 grade(s) of " << temp - 1 << "\n";
					outfile << numCount << " grade(s) of " << temp << "\n";
				}
				else
					outfile << numCount << " grade(s) of " << temp << "\n";
			}
			numCount = 0;
			appeared = 0;
			if (i == count - 1) {
				determine = 1;
			}
		}
	}
	outfile.close();
	return 0;
}

void selection_sort(int array[], int count) {
	for (int i = 0; i < count - 1; i++) {
		int MIN = i;
		for (int j = i + 1; j < count; j++) {
			if (array[j] < array[MIN]) {
				MIN = j;
			}
		}

		int temp = array[MIN];
		array[MIN] = array[i];
		array[i] = temp;
	}
}