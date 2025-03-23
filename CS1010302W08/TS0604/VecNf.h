/***********************************************************************
 * File: VecNf.h
 * Author: B11215002
 * Create Date: 2024/4/12
 * Editor: B11215002
 * Update Date: 2024/4/12
 * Description: This program is to store a multidimensional vector and implement some simple vector operations.
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>

class VecNf {
private:
	std::vector<float> input;
public:
	//constructor
	VecNf() {
		this->input.push_back(0);
	}

	//input constructor
	VecNf(float* dest, int cnt) {
		for (int i = 0; i < cnt; i++) {
			this->input.push_back(dest[i]);
		}
	}

	//input constructor
	VecNf(const VecNf& rhs) {
		for (int i = 0; i < rhs.input.size(); i++) {
			this->input.push_back(rhs.input[i]);
		}
	}

	// Intent: assign v1 to a new class member
	// Pre: take v1 as argument
	// Post: assign v1 to this class member
	VecNf& operator=(const VecNf& v1) {
		std::cout << "ASSIGNMENT!!!" << std::endl;
		int size = v1.input.size();

		//it was initialized with 0, clear it for a new vector space to be used
		input.clear();

		for (int i = 0; i < size; i++) {
			input.push_back(v1.input[i]);
		}

		return *this;
	}

	// Intent: overloading [] operator
	// Pre: take N as index 
	// Post: return the number at given index
	float& operator[](int n) {
		return input[n];
	}

	// Intent: overloading + operator
	// Pre: take v1, v2 as index 
	// Post: return the addition result
	friend VecNf operator+(VecNf& v1, VecNf& v2) {
		if (v1.input.size() != v2.input.size()) {
			std::cout << "dimensions inconsistent" << std::endl;

			//return a zero for inconsistent size
			VecNf zero;
			return zero;
		}

		VecNf result;
		result.input.clear();
		int size = v1.input.size();

		//do addition
		for (int i = 0; i < size; i++) {
			result.input.push_back(0);
			result.input[i] = v1.input[i] + v2.input[i];
		}

		return result;
	}


	// Intent: overloading - operator
	// Pre: take v1, v2 as index 
	// Post: return the subtration result
	friend VecNf operator-(VecNf& v1, VecNf& v2) {
		if (v1.input.size() != v2.input.size()) {
			std::cout << "dimensions inconsistent" << std::endl;

			//return a zero for inconsistent size
			VecNf zero;
			return zero;
		}

		VecNf result;
		result.input.clear();
		int size = v1.input.size();

		//do subtraction
		for (int i = 0; i < size; i++) {
			result.input.push_back(0);
			result.input[i] = v1.input[i] - v2.input[i];
		}

		return result;
	}

	// Intent: overloading * operator
	// Pre: take v1, v2 as index 
	// Post: return the multiplication result
	friend float operator*(VecNf& v1, VecNf& v2) {
		if (v1.input.size() != v2.input.size()) {
			std::cout << "dimensions inconsistent" << std::endl;

			//return a zero for inconsistent size
			return 0;
		}

		float result = 0.0;
		int size = v1.input.size();

		//do multiplication
		for (int i = 0; i < size; i++) {
			result += v1.input[i] * v2.input[i];
		}
		return result;
	}

	// Intent: overloading * operator for constant and vector v
	// Pre: take c, v as index 
	// Post: return the multiplication result for c times every element of v
	friend VecNf operator*(float c, VecNf& v) {
		VecNf result = v;
		int size = v.input.size();

		//do multiplication
		for (int i = 0; i < size; i++) {
			result.input[i] = v.input[i] * c;
		}

		return result;
	}

	// Intent: overloading * operator for constant and vector v
	// Pre: take c, v as index 
	// Post: return the multiplication result for c times every element of v
	friend VecNf operator*(VecNf& v, float c) {
		VecNf result = v;
		int size = v.input.size();

		//do multiplication
		for (int i = 0; i < size; i++) {
			result.input[i] = v.input[i] * c;
		}

		return result;
	}

	// Intent: return the size of input vector
	// Pre: call by Size()
	// Post: return the size
	int Size() {
		return input.size();
	}
};