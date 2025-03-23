/***********************************************************************
 * File: Polynomial.cpp
 * Author: B11215002
 * Create Date: 2024/4/4
 * Editor: B11215002
 * Update Date: 2024/4/8
 * Description: this is to design all the functions used for this question
***********************************************************************/
#include "Polynomial.h"

// Intent: Default constructor
Polynomial::Polynomial() {
	this->coefficients = { 0 };
}

// Intent: Constructor with inputs to set default value
Polynomial::Polynomial(double* param, int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			this->coefficients.push_back(param[i]);
		}
	}
	else {
		this->coefficients.push_back(0);
	}
}

// Intent: Constructor with a Class member as input
Polynomial::Polynomial(const Polynomial& poly) {
	int size = poly.coefficients.size();
	for (int i = 0; i < size; i++) {
		this->coefficients.push_back(poly.coefficients[i]);
	}
}

// Intent: Returning the size of the polynomial
// Pre: null
// Post: function returns the size of vector polynomial
int Polynomial::mySize() {
	int result = this->coefficients.size();
	//if it starts by non-zero coefficient, return the reuslt and minus one if otherwise
	for (int i = this->coefficients.size() - 1; i > -1; i--) {
		if (this->coefficients[i] != 0) {
			break;
		}
		else if (this->coefficients[i] == 0){
			result--;
		}
	}
	return result;
}

// Intent: Calculate the value by subsituting variable with input value
// Pre: null
// Post: function returns the result
double evaluate (const Polynomial& poly, const double& var) {
	double total = 0.0;
	int size = poly.coefficients.size(); 
	for (int i = 0; i < size; i++) {
		total += poly.coefficients[i] * pow(var, (i));
	}
	return total;
}

// Intent: operator overloading of []
// Pre: input the degree that user wants the coefficient of inside the []
// Post: function returns the coefficient
double& Polynomial::operator[] (int degree){
	//to avoid degree being out of size
	if (degree + 1 > this->coefficients.size()) {
		coefficients.resize(degree + 1);
	}
	return this->coefficients[degree];
}

// Intent: operator overloading of []
// Pre: input the degree that user wants the coefficient of inside the []
// Post: function returns the coefficient but as a constant
double Polynomial::operator[](int degree) const{
	return this->coefficients[degree];
}

// Intent: operator overloading of =
// Pre: assign one polynomial to another polynomial
// Post: function returns the pointer to the newly assigned polynoimial
Polynomial& Polynomial::operator= (const Polynomial& poly) {
	coefficients.clear();
	this->coefficients = std::vector<double>(poly.coefficients);
	return *this;
}

// Intent: operator overloading of +
// Pre: add one polynomial to another polynomial
// Post: function returns the addition result
Polynomial operator+ (Polynomial& first, Polynomial& second) {
	Polynomial temp;
	int size;

	//set size for later initialization
	if (first.coefficients.size() >= second.coefficients.size()) {
		size = first.coefficients.size();
	}
	else {
		size = second.coefficients.size();
	}

	//initialize
	for (int i = 0; i < size; i++) {
		temp.coefficients.push_back(0);
	}

	//addition base on the larger polynomial to avoid misalign
	if (first.coefficients.size() >= second.coefficients.size()) {
		for (int i = 0; i < first.coefficients.size(); i++) {
			temp.coefficients[i] = first.coefficients[i];
		}
		for (int i = 0; i < second.coefficients.size(); i++) {
			temp.coefficients[i] += second.coefficients[i];
		}
	}
	else {
		for (int i = 0; i < second.coefficients.size(); i++) {
			temp.coefficients[i] = second.coefficients[i];
		}
		for (int i = 0; i < first.coefficients.size(); i++) {
			temp.coefficients[i] += first.coefficients[i];
		}
	}
	return temp;
}

// Intent: operator overloading of +
// Pre: add one constant to another polynomial
// Post: function returns the addition result
Polynomial operator+ (double first, const Polynomial& second) {
	Polynomial temp = second;
	temp.coefficients[0] += first;
	return temp;
}

// Intent: operator overloading of +
// Pre: add one constant to another polynomial
// Post: function returns the addition result
Polynomial operator+ (const Polynomial& first, double second) {
	Polynomial temp = first;
	temp.coefficients[0] += second;
	return temp;
}

// Intent: operator overloading of -
// Pre: subtract one polynomial by another polynomial
// Post: function returns the subtraction result
Polynomial operator- (const Polynomial& first, const Polynomial& second) {
	Polynomial temp;
	int size;

	//set size for later initialization
	if (first.coefficients.size() >= second.coefficients.size()) {
		size = first.coefficients.size();
	}
	else {
		size = second.coefficients.size();
	}

	//initialize
	for (int i = 0; i < size - 1; i++) {
		temp.coefficients.push_back(0);
	}

	//substract
	for (int i = 0; i < first.coefficients.size(); i++) {
		temp.coefficients[i] = first.coefficients[i];
	}
	for (int i = 0; i < second.coefficients.size(); i++) {
		temp.coefficients[i] -= second.coefficients[i];
	}
	return temp;
}

// Intent: operator overloading of -
// Pre: subtract one constant by a polynomial
// Post: function returns the subtraction result
Polynomial operator- (double first, const Polynomial& second) {
	Polynomial temp = second;
	for (int i = 1; i < second.coefficients.size(); i++) {
		temp[i] *= -1;
	}
	temp.coefficients[0] = first - temp.coefficients[0];
	return temp;
}

// Intent: operator overloading of -
// Pre: subtract one polynomial by a constant
// Post: function returns the subtraction result
Polynomial operator- (const Polynomial& first, double second) {
	Polynomial temp = first;
	temp.coefficients[0] -= second;
	return temp;
}

// Intent: operator overloading of *
// Pre: multiply one polynomial by another polynomial
// Post: function returns the multiplication result
Polynomial operator*(const Polynomial& first, const Polynomial& second) {
	//if either one is zero, return it by empty polynomial
	if (first.coefficients.size() == 0 && first.coefficients[0] == 0) {
		return Polynomial();
	}
	if (second.coefficients.size() == 0 && second.coefficients[0] == 0) {
		return Polynomial();
	}

	//find largest degree and get the sum of it
	int topDegree = first.coefficients.size() - 1 + second.coefficients.size() - 1;

	//initialize
	Polynomial temp;
	for (int i = 0; i < topDegree; i++) {
		temp.coefficients.push_back(0);
	}

	//multiply
	for (int i = 0; i < first.coefficients.size(); i++) {
		for (int j = 0; j < second.coefficients.size(); j++) {
			//degree = coef1 * coef2
			temp[i + j] += first.coefficients[i] * second.coefficients[j];
		}
	}
	return temp;
}

// Intent: operator overloading of *
// Pre: multiply one constant by a polynomial
// Post: function returns the multiplication result
Polynomial operator* (double first, const Polynomial& second) {
	int size = second.coefficients.size();
	Polynomial temp = second;
	for (int i = 0; i < size; i++) {
		temp.coefficients[i] *= first;
	}
	return temp;
}

// Intent: operator overloading of *
// Pre: multiply one polynomial by a constant
// Post: function returns the multiplication result
Polynomial operator* (const Polynomial& first, double second) {
	int size = first.coefficients.size();
	Polynomial temp = first;
	for (int i = 0; i < size; i++) {
		temp.coefficients[i] *= second;
	}
	return temp;
}