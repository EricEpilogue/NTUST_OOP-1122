/***********************************************************************
 * File: Polynomial.h
 * Author: B11215002
 * Create Date: 2024/4/4
 * Editor: B11215002
 * Update Date: 2024/4/8
 * Description: This program is to set function prototypes for this question
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class Polynomial {
private:
	std::vector<double> coefficients;
public:
	Polynomial(); //default constructor
	Polynomial(double* param, int size); //input constructor
	Polynomial(const Polynomial& poly); //input constructor
	int mySize(); //return the size of vector
	friend double evaluate(const Polynomial& poly, const double& var); //use the value to calculate the total value of the formula
	double& operator[](int degree); //return the specified coefficients of the entered degree
	double operator[](int index) const;
	Polynomial& operator=(const Polynomial& poly); //assign one formula to another
	
	//do addition with another Polynomial or with a constant
	friend Polynomial operator+(Polynomial& first, Polynomial& second);
	friend Polynomial operator+(double first, const Polynomial& second);
	friend Polynomial operator+(const Polynomial& first, double second);

	//do subtraction with another Polynomial or with a constant
	friend Polynomial operator-(const Polynomial& first, const Polynomial& second);
	friend Polynomial operator-(double first, const Polynomial& second);
	friend Polynomial operator-(const Polynomial& first, double second);

	//do multiplication with another Polynomial or with a constant
	friend Polynomial operator*(const Polynomial& first, const Polynomial& second);
	friend Polynomial operator*(double first, const Polynomial& second);
	friend Polynomial operator*(const Polynomial& first, double second);
};
