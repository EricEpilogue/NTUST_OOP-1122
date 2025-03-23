/***********************************************************************
 * File: Complex.h
 * Author: B11215002
 * Create Date: 2024/4/12
 * Editor: B11215002
 * Update Date: 2024/4/12
 * Description: This program is to do complex number calculations
***********************************************************************/

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

class Complex
{
private:
	double realValue, imaginaryValue;
public:
	//constructor
	Complex() {
		realValue = 0.0;
		imaginaryValue = 0.0;
	}

	//input constructor
	Complex(double r) {
		imaginaryValue = 0.0;
		realValue = r;
	}

	//input constructor
	Complex(double r, double i) {
		imaginaryValue = i;
		realValue = r;
	}

	// Intent: to return the real part of the complex
	// Pre: call by real() command;
	// Post: returns the real part of the complex
	double real() { return this->realValue; }

	// Intent: to return the imaginary part of the complex
	// Pre: call by imag()
	// Post: returns imaginary value
	double imag() { return this->imaginaryValue; }

	// Intent: to return the norm
	// Pre: call by norm()
	// Post: calculate and returns the norm
	double norm() {
		double result;
		result = sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
		return result;
	}

	// Intent: to return the real value of C
	// Pre: call by real(Complex c)
	// Post: return the real value of C
	friend double real(Complex c) { return c.realValue; }

	// Intent: to return the imaginary value of C
	// Pre: call by imag(Complex c)
	// Post: return the imaginary value of C 
	friend double imag(Complex c) { return c.imaginaryValue; }

	// Intent: to return the norm of C
	// Pre: call by norm(Complex c)
	// Post: return the norm of C 
	friend double norm(Complex c) {
		double result;

		result = sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));

		return result;
	}

	// Intent: to do complex addition
	// Pre: complex set c1 and complex set c2
	// Post: do complex addition and returns the complex set result
	friend Complex operator+(Complex c1, Complex c2) {
		Complex result;

		//do addiction
		result.realValue = c1.realValue + c2.realValue;
		result.imaginaryValue = c1.imaginaryValue + c2.imaginaryValue;

		return result;
	}

	// Intent: to do complex subtraction
	// Pre: complex set c1 and complex set c2
	// Post: do complex subtraction and returns the complex set result
	friend Complex operator-(Complex c1, Complex c2) {
		Complex result = c1;

		//do subtraction
		result.realValue -= c2.realValue;
		result.imaginaryValue -= c2.imaginaryValue;

		return result;
	}

	// Intent: to do complex multiplication
	// Pre: complex set c1 and complex set c2
	// Post: do complex multiplication and returns the complex set result
	friend Complex operator*(Complex c1, Complex c2) {
		Complex result;

		result.realValue = c1.realValue * c2.realValue;
		result.imaginaryValue = c1.realValue * c2.imaginaryValue + c1.imaginaryValue * c2.realValue;
		
		//i squared is -1
		result.realValue += c1.imaginaryValue * c2.imaginaryValue * (-1);
		return result;
	}

	// Intent: to do complex division
	// Pre: complex set c1 and complex set c2
	// Post: do complex division and returns the complex set result
	friend Complex operator/(Complex c1, Complex c2) {
		Complex result;
		Complex temp = c2;

		//use rationalize to compute the complex set
		temp.imaginaryValue *= -1;
		c1 = c1* temp;
		//c2 imaginary will be 0
		c2 = c2* temp; 
		double carry = c2.realValue;
		result.realValue = c1.realValue / carry;
		result.imaginaryValue = c1.imaginaryValue / carry;
		return result;
	}

	// Intent: do complex addition but with a constant
	// Pre: complex1 and constant C
	// Post: add the real part with constant C
	friend Complex operator+(double d, Complex c) {
		Complex result = c;
		result.realValue += d;
		return result;
	}

	// Intent: do complex subtraction but with a constant (d, 0i) - (c , ci)
	// Pre: complex1 and constant C
	// Post: subtract the real part with constant C
	friend Complex operator-(double d, Complex c) {
		Complex result = c;
		result.imaginaryValue *= -1;
		result.realValue *= -1;
		result.realValue += d;
		return result;
	}

	// Intent: do complex subtraction but with a constant (c, ci) - (d , 0i)
	// Pre: complex1 and constant C
	// Post: subtract the real part with constant C
	friend Complex operator-(Complex c, double d) {
		Complex result = c;
		result.realValue -= d;
		return result;
	}

	// Intent: do complex multiplication but with a constant
	// Pre: complex1 and constant C
	// Post: multiply the real and imaginary part both by d
	friend Complex operator*(double d, Complex c) {
		Complex result = c;
		result.realValue *= d;
		result.imaginaryValue *= d;
		return result;
	}

	// Intent: do complex division but with a constant
	// Pre: complex1 and constant C
	// Post: division the real and imaginary part both by d
	friend Complex operator/(double d, Complex c2) {
		Complex result;
		//transform d into the complex format with 0*i
		Complex c1(d , 0);
		Complex temp = c2;

		//use rationalize to compute
		temp.imaginaryValue *= -1;
		c1 = c1 * temp;
		//c2 imaginary will be 0
		c2 = c2 * temp; 
		double carry = c2.realValue;
		result.realValue = c1.realValue / carry;
		result.imaginaryValue = c1.imaginaryValue / carry;
		return result;
	}

	// Intent: check whether c1 equals to c2
	// Pre: complex c1 and complex c2 as argument
	// Post: return true or false
	friend bool operator==(Complex c1, Complex c2) {
		if (c1.imaginaryValue == c2.imaginaryValue && c1.realValue == c2.realValue) {
			return true;
		}
		return false;
	}

	// Intent: output operator overload to allow cout with complex format
	// Pre: call << operator with complex class member 
	// Post: output a + bi
	friend ostream& operator<<(ostream& strm, const Complex& c) {
		strm << c.realValue << " + " << c.imaginaryValue << "*i";
		return strm;
	}

	// Intent: input operator overload to allow cin with complex format
	// Pre: call >> operator with complex class member 
	// Post: get input to store as a new class member
	friend istream& operator>>(istream& strm, Complex& c) {
		std::string input;
		std::getline(strm, input); // Read the entire line

		// Find the position of '=' and '+'
		size_t posEqual = input.find('=');
		size_t posPlus = input.find('+');

		// Extract real part
		std::string realNum = input.substr(posEqual + 1, posPlus - posEqual - 1);
		std::istringstream(realNum) >> c.realValue;

		// Extract imaginary part
		std::string imaginaryNum = input.substr(posPlus + 1);
		std::istringstream(imaginaryNum) >> c.imaginaryValue;

		return strm;
	}
};
