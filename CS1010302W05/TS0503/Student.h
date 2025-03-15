/***********************************************************************
 * File: Student.h
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to keep records of at most 10 student data by structures
***********************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype> 

//StRec structure provided by the docx file
typedef struct {
    char firstName[25];
    char lastName[30];
    char phone[15];
} StRec;

class Student {
private:
	StRec info;
	std::vector<StRec> people; //to store all the entries
public:
	// Intent: default constructor
	Student() {
	}


	// Intent: function to determine input errors
	// Pre: The variable could be incorrect
	// Post: filter out anything that doesn't comply within the rules
	bool determine(std::string first, std::string last, std::string phoneNum) {
		//check if first name's validate
		if (first.length() > 25) {
			std::cout << "Input Error" << std::endl;
			return false;
		}	

		//check if last name's validate
		if(last.length() > 30) {
			std::cout << "Input Error" << std::endl;
			return false;
		}

		//check if phone number's validate
		if (phoneNum.length() > 30) {
			std::cout << "Input Error" << std::endl;
			return false;
		}

		//run and check if phone number is in all numbers
		for (char c : phoneNum) {
			if (!isdigit(c)) {
				std::cout << "Input Error" << std::endl;
				return false;
			}
		}

		//all of these passed, return input is vaildate(true)
		return true;
	}

	// Intent: insert function to push items into vector and store it
	// Pre: The input is not in the vector
	// Post: check and store the entry into vector
	void insert() {
		std::string first;
		std::string last;
		std::string phoneNum;
		std::cin >> first >> last >> phoneNum;
		
		// check for input invalidation
		if (determine(first, last, phoneNum) == false) {
			return;
		}
		
		//check for insert error where same token already exists
		if (checkExist(first, last, phoneNum) == true) {
			std::cout << "Insert Error" << std::endl;
			return;
		}

		//check for insert error where 10 entries already exist
		if (people.size() >= 10) {
			std::cout << "Insert Error" << std::endl;
			return;
		}

		//convert character array into strings and into 1 item in the vector
		strcpy_s(info.firstName, first.c_str());
		strcpy_s(info.lastName, last.c_str());
		strcpy_s(info.phone, phoneNum.c_str());

		people.push_back(info);
	}

	// Intent: delete function where it searches and delete things that it found matching
	// Pre: The input is in the vector
	// Post: check and delete the entry out of vector
	void deleteo() {
		std::string first;
		std::string last;
		std::string phoneNum;
		std::cin >> first >> last >> phoneNum;
		
		//for input error
		if (determine(first, last, phoneNum) == false) {
			return;
		}

		//if non-existent, just return delete error
		if (checkExist(first, last, phoneNum) == false) {
			std::cout << "Delete Error" << std::endl;
			return;
		}

		//delete algorithm
		for (int i = 0; i < people.size(); i++) {
			if (people[i].firstName == first && people[i].lastName == last && people[i].phone == phoneNum) {
				people.erase(people.begin() + i);
				return;
			}
		}
	}

	// Intent: search function where it searches and tell where student data is
	// Pre: Get input
	// Post: Return the index of matching item
	void search() {
		std::string first;
		std::string last;
		std::string phoneNum;
		std::cin >> first >> last >> phoneNum;
		
		//check for input errors
		if (determine(first, last, phoneNum) == false) {
			return;
		}

		//loop through the vector to find the index where all requirements are met
		for (size_t i = 0; i < people.size(); i++) {
			if (people[i].firstName == first && people[i].lastName == last && people[i].phone == phoneNum) {
				std::cout << i << std::endl;
				return;
			}
		}

		//case if not found
		std::cout << "Search Error" << std::endl;		
	}

	// Intent: search function where it searches whether item exists or not
	// Pre: Get input
	// Post: check whether it exists or not by returning true or false
	bool checkExist(std::string first, std::string last, std::string phoneNum) {
		//loop through the vector but it doesnt return the index value
		for (size_t i = 0; i < people.size(); i ++) {
			if (people[i].firstName == first && people[i].lastName == last && people[i].phone == phoneNum) {
				return true;
			}
		}

		return false;
	}

	// Intent: print function that prints everything in the vector
	// Pre: Get the command print
	// Post: if validate, print everything stored
	void print() {
		//if it's empty then it's print error
		if (people.size() == 0) {
			std::cout << "Print Error" << std::endl;
			return;
		}

		//if not, print everything
		else {
			for (size_t i = 0; i < people.size(); i ++) {
				std::cout << people[i].firstName << " " << people[i].lastName << " " << people[i].phone << std::endl;
			}
		}
	}
};