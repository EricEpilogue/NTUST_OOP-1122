/***********************************************************************
 * File: Main.cpp
 * Author: B11215002
 * Create Date: 2024/02/22
 * Editor: B11215002
 * Update Date: 2024/02/22
 * Description: This program is to compute and ouput the volume of a sphere with radius r.
***********************************************************************/

#include <iostream>

#define PI 3.14159265358979323846

int main(int argc, char **argv) {

	//take r as input
	double r;
	std::cin >> r;

	while (!std::cin.eof()) {

		//calculate
		double volume = 0.0;
		volume = (double)  4 * r * r * r * PI;
		volume /= 3;

		//output
		printf("%.6f\n", volume);

		//scan again
		std::cin >> r;
	}
}