#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
	int input = 0;
	std::cin >> input;
	while (!std::cin.eof()) {
		if (input < 750) {
			std::cout << std::fixed << std::setprecision(2) << input * 0.01 << std::endl;
		}
		else if (input >= 750 && input < 2250) {
			std::cout << std::fixed << std::setprecision(2) << 7.5 + (input-750) * 0.02 << std::endl;
		}
		else if (input >= 2250 && input < 3750) {
			std::cout << std::fixed << std::setprecision(2) << 37.5 + (input - 2250) * 0.03 << std::endl;
		}
		else if (input >= 3750 && input < 5250) {
			std::cout << std::fixed << std::setprecision(2) << 82.5 + (input - 3750) * 0.04 << std::endl;
		}
		else if (input >= 5250 && input < 7000) {
			std::cout << std::fixed << std::setprecision(2) << 142.5 + (input - 5250) * 0.05 << std::endl;
		}
		else if (input >= 7000) {
			std::cout << std::fixed << std::setprecision(2) << 230 + (input - 7000) * 0.06 << std::endl;
		}
		else {
			return 0;
		}
		std::cin >> input;
	}
}