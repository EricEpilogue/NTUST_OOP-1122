#include "Fraction.h"

void Fraction::setNumerator(double nu)
{
	this->numerator = nu;
}

void Fraction::setDenominator(double de)
{
	this->denominator = de;
}

void Fraction::getDouble()
{	
	result = (double)numerator / (double)denominator;
	int x = ceil(result);
	if (result == 1) {
		std::cout << (int)result << std::endl;
		return;
	}
	if (x == result) {
		std::cout << result << std::endl;
		return;
	}
	else if (x != result){
		std::cout << std::fixed << std::setprecision(6) << result << std::endl;
		return;
	}
}

void Fraction::outputReducedFraction()
{
	if (this->numerator == 0) {
		std::cout << "0" << std::endl;
		return;
	}
	int temp = 0;
	for (int i = 1; i <= std::min(this->numerator, this->denominator); i++) {
		if (this->numerator % i == 0 && this->denominator % i == 0) {
			temp = i;
		}
	}
	this->numerator /= temp;
	this->denominator /= temp;
	if(this->denominator != 1)
		std::cout << this->numerator << "/" << this->denominator << std::endl;
	if (this->denominator == 1)
		std::cout << this->numerator << std::endl;
}



