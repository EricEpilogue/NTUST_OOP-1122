/***********************************************************************
 * File: NumberGame.h
 * Author: B11215002
 * Create Date: 2024/4/12
 * Editor: B11215002
 * Update Date: 2024/4/12
 * Description: This program is to do design the fundemental functions of the number game
***********************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class NumberGame {
private:
	int input = 0;
	std::vector<unsigned int> digitList;
	std::vector<unsigned int> valid;
	std::vector<unsigned int> output;
	std::string fileName;
public:
	// Intent: to set a as the input
	// Pre: take argument a 
	// Post: set input = a
	void SetInput(int a) {
		this->input = a;
	}

	// Intent: push back all the digits from input
	// Pre: multi digit number input 
	// Post: derive all the digits and store it in a vector
	void ProcessInput() {
		int digit = 0;

		while (input > 0) {
			digit = this->input % 10;
			this->digitList.push_back(digit);
			this->input /= 10;
		}
	}

	// Intent: to set filename as the user input
	// Pre: take name as file name for comparison file
	// Post: set fileName as name set by user
	void SetFileName(std::string name) {
		this->fileName = name;
	}

	// Intent: a recursive function to find all possible multiplication by the digit composition
	// Pre: take the digit vector as input, the first index, the product by each digits and another vector of all validate products
	// Post: if the index matches the amount of number used, store it's product in vector valid
	void findCombination(const std::vector<unsigned int> nums, int index, int currentProduct, std::vector<unsigned int>& valid) {
		if (index == nums.size()) {
			valid.push_back(currentProduct);
			return;
		}

		findCombination(nums, index + 1, currentProduct, valid);
		findCombination(nums, index + 1, currentProduct * nums[index], valid);
	}

	// Intent: to open filename.txt and compare the valid vector with it
	// Pre: open file and compare
	// Post: store all matching results into output vector for later use
	void LoadNumberList() {
		std::ifstream inputFile;
		inputFile.open(fileName);
		int target;

		//call function
		findCombination(digitList, 0, 1, valid);

		//loop through the file
		while (inputFile >> target) {
			//loop through the valid vector
			for (auto& i : valid) {
				int matches = (int)i;
				//if validate, store into output
				if (matches == target) {
					output.push_back(target);
					break;
				}
			}
		}
	}

	// Intent: print everything valid
	// Pre: take output vector
	// Post: print everything accordingly
	void PrintAllValid() {
		//sort ascendingly
		std::sort(digitList.begin(), digitList.end());
		int determine = 0;
		int min = digitList[0];

		for (int i = 0; i < output.size(); i++) {
			if (output[i] < min)
				continue;
			std::cout << output[i] << std::endl;
		}
	}

	// Intent: reset variables and vectors
	// Pre: pre-loaded from previous inputs
	// Post: reset everything to empty
	void Reset() {
		input = 0;
		digitList.clear();
		valid.clear();
		output.clear();
	}
};