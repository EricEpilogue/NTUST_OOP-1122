/***********************************************************************
 * File: Atoi.h
 * Author: B11215002
 * Create Date: 2024/03/28
 * Editor: B11215002
 * Update Date: 2024/03/29
 * Description: This program is to design the Atoi class that fulfills the requirements of array to integer.
***********************************************************************/

#include <string>
using namespace std;

class Atoi {

private:
	string beTrans;
	int sign = 1;
public:
	//default constructor
	Atoi() {
		beTrans = "";
	}

	//input constructor that detects negative sign
	Atoi(string s) {
		beTrans = s;
		if (beTrans[0] == '-') {
			beTrans.erase(0, 1);
			sign = -1;
		}
	}

	//input constructor that detects negative sign
	void SetString(string s) {
		beTrans = s;
		if (beTrans[0] == '-') {
			beTrans.erase(0, 1);
			sign = -1;
		}
	}

	//returns the string that awaits to be transformed
	const string GetString() {
		return this->beTrans;
	}

	//returns the length of the string that awaits to be transformed
	int Length() {
		return beTrans.length();
	}

	// Intent: To check whether the input is valid or not
	// Pre: beTrans string could be anything
	// Post: True or false
	bool IsDigital() {
		int length = beTrans.length();

		for (int i = 0; i < length; i++) {
			if (!isdigit(beTrans[i])) {
				return false;
			}
		}

		return true;
	}

	// Intent: To transform string full of numbers into integer array 
	// Pre: characters
	// Post: integers
	int StringToInteger() {
		int output = 0;
		
		if (IsDigital() == true) {
			int length = beTrans.length();

			for (size_t i = 0; i < length; i++) {
				if (i == 0) {
					//char - '0' = integer
					output += beTrans[length - i - 1] - '0';
				}
				else if (i > 0){
					output += (beTrans[length - i - 1] - '0') * pow(10, i);
				}
			}
		}

		output *= sign;

		return output;
	}

};