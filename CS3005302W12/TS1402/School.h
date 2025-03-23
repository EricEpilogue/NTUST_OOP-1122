/***********************************************************************
 * File: School.h
 * Author: B11215002
 * Create Date: 2024/5/11
 * Editor: B11215002
 * Update Date: 2024/5/11
 * Description: A school entrance simulation program
***********************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <math.h>

class School {
public:
	std::string name;
	int studentAmount;
	int studentAmountNextYear = studentAmount;

	//constructor
	School() {
		this->name = "";
		this->studentAmount = 0;
		this->studentAmountNextYear = this->studentAmount;
	}

	//constructor
	School(std::string input, int intInput) {
		this->name = input;
		this->studentAmount = intInput;
		this->studentAmountNextYear = this->studentAmount;
	}

	// Intent: Adjust the admissions for this year
	// Pre: uses input as parameter
	// Post: add the amount to this year's student amount
	void admissions(float amount) {
		this->studentAmount = this->studentAmount + amount;
		return;
	}

	// Intent: virtual function for dropouts
	// Pre: uses input as parameter
	// Post: subtract the amount to this year's student amount
	virtual void dropouts(float amount) {
		this->studentAmount = this->studentAmount - amount;
		if (!viable(studentAmount)) {
			this->studentAmount = this->studentAmount + amount;
			return;
		}
		return;
	}

	// Intent: get certain amount of student from A school to B school
	// Pre: from A school transfer certain amount to B school 
	// Post: transfered
	void transfer(float amount, School& toSchool) {
		dropouts(amount);
		toSchool.admissions(amount);

		return;
	}

	// Intent: To check if the student count goes negative
	// Pre: call function viable()
	// Post: return true or false
	bool viable(float input) {
		if (input < 0) {
			return false;
		}
		return true;
	}

	// Intent: operator overload for output
	// Pre: call cout for every variable
	// Post: simplier output call
	friend std::ostream& operator<<(std::ostream& cout, const School& school) {
		cout << school.name << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear;
		return cout;
	}
};

class PublicSchool : public School {
private:
	float growing_rate = 0.05;
public:
	//constructor
	PublicSchool() {
		this->name = "";
		this->studentAmount = 0;
		this->studentAmountNextYear = this->studentAmount;
	}

	//constructor
	PublicSchool(std::string input, int intInput) {
		this->name = input;
		this->studentAmount = intInput;
		this->studentAmountNextYear = this->studentAmount;
	}

	// Intent: incease the student acceptable next year 
	// Pre: studentAmountNextYear
	// Post: studentAmountNextYear * growing_rate
	void apply_growth() {
		this->studentAmountNextYear += growing_rate * studentAmountNextYear;
	}

	// Intent: overloading the dropout function
	// Pre: uses input as parameter
	// Post: subtract the amount to this year's student amount, also give penalty
	void dropouts(float amount) override {
		studentAmount = this->studentAmount - amount;

		if (!viable(studentAmount)) {
			this->studentAmount = this->studentAmount + amount;
			return;
		}
		if (amount >= 100) {
			this->studentAmountNextYear *= 0.95;
			trunc(studentAmountNextYear);
		}

		return;
	}

	// Intent: operator overload for output
	// Pre: call cout for every variable
	// Post: simplier output call
	friend std::ostream& operator<<(std::ostream& cout, PublicSchool& school) {
		cout << school.name << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear;
		return cout;
	}
};

class PrivateSchool : public School {
private:
	int waveCount = 0;
public:
	//constructor
	PrivateSchool() {
		this->name = "";
		this->studentAmount = 0;
		this->studentAmountNextYear = this->studentAmount;
		this->waveCount = 0;
	}

	//constructor
	PrivateSchool(std::string input, int intInput) {
		this->name = input;
		this->studentAmount = intInput;
		this->studentAmountNextYear = this->studentAmount;
		this->waveCount = 0;
	}

	// Intent: overloading the dropout function
	// Pre: uses input as parameter
	// Post: subtract the amount to this year's student amount, also give penalty
	void dropouts(float amount) override{
		if (waveCount > 0) {
			studentAmountNextYear -= 100;
		}

		this->studentAmount = this->studentAmount - amount;
		if (!viable(studentAmount)) {
			this->studentAmount = this->studentAmount + amount;
			return;
		}

		waveCount++;

		return;
	}

	// Intent: operator overload for output
	// Pre: call cout for every variable
	// Post: simplier output call
	friend std::ostream& operator<<(std::ostream& cout, const PrivateSchool& school) {
		cout << school.name << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear;
		return cout;
	}
};