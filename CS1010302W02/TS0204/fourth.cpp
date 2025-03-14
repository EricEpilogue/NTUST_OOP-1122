/***********************************************************************
 * File: fourth.cpp
 * Author: B11215002
 * Create Date: 2024/03/02
 * Editor: B11215002
 * Update Date: 2023/03/02
 * Description: This program is to print out N employee's information, Name, Salary and Bonus. 
***********************************************************************/

#include<iostream>
#include<string> //to use string to store different data types

int countintLength(long int input); // function to calculate how many digit an input integer has

int main(int argc, char** argv) {
	//read input until EOF as required
	while (!std::cin.eof()) {
		//initializing every variable
		long int numberOf = 0;
		std::string name;
		long int salary = 0;
		long int bonus = 0;
		int nameLength = 0;
		int salaryLength = 0;
		int bonusLength = 0;
		std::string outputName[100];
		int outputSalary[100] = { 0 };
		int outputBonus[100] = { 0 };
		int m = 0;
		int n = 0;
		int k = 0;

		//get the total number
		std::cin >> numberOf;

		for (int i = 0; i < numberOf; i++) {

			std::cin >> name >> salary >> bonus;

			//get longest name length
			if (name.length() > nameLength)
				nameLength = name.length();

			//get longest salary length
			if (countintLength(salary) > salaryLength)
				salaryLength = countintLength(salary);

			//get longest bonus length
			if (countintLength(bonus) > bonusLength)
				bonusLength = countintLength(bonus);

			//store input in to an array for output
			outputName[i] = name;
			outputSalary[i] = salary;
			outputBonus[i] = bonus;
		}

		//print everything accordingly
		for (int j = 0; j < numberOf; j++) {
			//line up the output by inseting spaces
			for (int i = 0; i < (nameLength - outputName[j].length()); i++) {
				std::cout << " ";
			}

			//print the Name
			std::cout << outputName[m++] << "|  ";

			//line up the output by inseting spaces
			for (int i = 0; i < (salaryLength - countintLength(outputSalary[j])); i++) {
				std::cout << " ";
			}

			//print the Salary
			std::cout << outputSalary[n++] << "|  ";

			//line up the output by inseting spaces
			for (int i = 0; i < (bonusLength - countintLength(outputBonus[j])); i++) {
				std::cout << " ";
			}

			//print the Bonus
			std::cout << outputBonus[k++] << std::endl;
		}
	}
}

// Intent: Count the length of an input
// Pre: nothing
// Post: how many digits the input has.
int countintLength(long int input) {
	int length = 0;

	while (input > 9) {
		input /= 10;
		length++;
	}

	length++;
	return length;
}