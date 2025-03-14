#ifndef Fraction_H
#define Fraction_H
#include <iostream>
#include <iomanip>
#include <math.h>

class Fraction
{
private:
	int numerator = 0.0;
	int denominator = 0.0;
	long double result = 0.0;
public: 
	void setNumerator(double nu);
	void setDenominator(double de);
	void getDouble();
	void outputReducedFraction();

};

#endif //Fraction_H