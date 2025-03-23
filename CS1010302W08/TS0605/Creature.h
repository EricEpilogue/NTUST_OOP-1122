#pragma once
#include<iostream>
#include<vector>
#include<string>

class Creature {
private:
	std::string name;
	std::vector<std::string> bodyPart;
	std::vector<int> partCount;
	int index = 0;
public:
	Creature(std::string nameStr) {
		this->name = nameStr;
	}

	Creature(std::string nameStr, Creature base) {
		this->name = nameStr;
		this->bodyPart = base.bodyPart;
		this->partCount = base.partCount;
	}

	void operator[](std::string part) {
		for (int i = 0; i < bodyPart.size(); i++) {
			if (bodyPart[i] == part) {
				this->index = i;
			}
		}
	}

	void operator=(int input) {
		partCount[index] = input;
	}


};