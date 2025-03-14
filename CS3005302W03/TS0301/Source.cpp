#include <iostream>

const int SIZE = 2000;

void selection_sort(int array[], int count);

int main(int argc, char** argv) {
	int num[SIZE];
	int input = 0;
	int count = 0;

	while (std::cin >> input) {
		num[count++] = input;
	}

	/*for (int i = 0; i < count; i++) {
		std::cout << num[i] << " ";
	}*/
	selection_sort(num, count);

	int temp = 0;
	int numCount = 0;
	int determine = 0;
	std::cout << "N\tcount" << std::endl;
	int appeared = 0;
	int outputList[SIZE] = { 0 };
	while (determine == 0) {
		for (int i = 0; i < count; i++) {
			temp = num[i]; 
			outputList[i] = temp;
			//std::cout << temp << std::endl;
			for (int j = 0; j < count; j++) {
				if (temp == num[j])
					numCount++;
					//std::cout << numCount << std::endl;
			}
			for (int k = 0; k < i; k++) {
				if (num[i] == outputList[k]) {
						appeared = 1;
				}
			}
			if(appeared == 0)
				std::cout << temp << "\t" << numCount << std::endl;
			numCount = 0;
			appeared = 0;
			if (i == count - 1) {
				determine = 1;
			}
		}
	}
}

void selection_sort(int array[], int count) {
	for (int i = 0; i < count - 1; i++) {
		int MAX = i;
		for (int j = i + 1; j < count; j++) {
			if (array[j] > array[MAX]) {
				MAX = j;
			}
		}
		
		int temp = array[MAX];
		array[MAX] = array[i];
		array[i] = temp;
	}
}