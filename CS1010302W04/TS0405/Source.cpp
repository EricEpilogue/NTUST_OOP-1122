#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	int input1 = 0;
	int input2 = 0; 
	std::cin >> input1 >> input2;
	while (!std::cin.eof()) {
		std::cout << input1 << " " << input2 << " ";
		int maxCycle = 0;
		std::vector<int> cycle;
		for (int k = std::min(input1, input2); k <= std::max(input1, input2); k++) {
			int i = k;
			while (i != 1) {
				if (i % 2 == 1) {
					i *= 3;
					i += 1;
					maxCycle++;
				}
				else if (i % 2 == 0) {
					i /= 2;
					maxCycle++;
				}
			}
			if (i == 1) {
				maxCycle++;
				cycle.push_back(maxCycle);
				maxCycle = 0;
			}
		}
		int MAX = 0;
		for (int i = 0; i < cycle.size(); i++) {
			if (cycle[i] > MAX)
				MAX = cycle[i];
		}
		std::cout << MAX << std::endl;
		std::cin >> input1 >> input2;
	}
}