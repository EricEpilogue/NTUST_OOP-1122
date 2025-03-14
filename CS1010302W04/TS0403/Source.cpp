#include <iostream>

int main(int argc, char **argv) {
	int a = 0;
	int b = 0;
	while (std::cin >> a >> b) {
		int temp = 0;
		for (int i = 1; i <= std::min(a, b); i++) {
			if (a % i == 0 && b % i == 0) {
				temp = i;
			}
		}
		std::cout << temp << std::endl;
	}
}