/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/05/22
 * Editor: B11215002
 * Update Date: 2024/05/28
 * Description: This program is to practice how set works
***********************************************************************/

#include <iostream>
#include <set>
#include <string>
#include <fstream>

int main() {
	//read file
	std::ifstream inFile;
	inFile.open("name.txt");
	std::string names;
	std::set<std::string> nameList;

	while (std::getline(inFile, names)) {
		//equal to 1 means there's existing names already
		if(nameList.count(names) != 1)
			nameList.insert(names);
	}

	//print the result
	for (auto& it : nameList) {
		std::cout << it << std::endl;
	}

	//close the file
	inFile.close();
	return 0;
}