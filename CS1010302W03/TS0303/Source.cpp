#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

const int SIZE = 50;

int main(int argc, char** argv) {
	double X;
	long M;
	long N;
	char C;
	std::cin >> X >> M >> N;
	std::cin >> std::ws >> C;
	while (!std::cin.eof()) {
		X *= pow(10, N);
		X = trunc(X) / pow(10, N);
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(N) << X;
		std::string output = oss.str();
		if (output.length() < M) {
			output.insert(0, (int)(M - output.length()), C);
		}
		std::cout << output << std::endl;
		std::cin >> X >> M >> N;
		std::cin >> std::ws >> C;
		oss.str("");
	}
}