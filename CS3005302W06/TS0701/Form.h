/***********************************************************************
 * File: Form.h
 * Author: B11215002
 * Create Date: 2024/03/28
 * Editor: B11215002
 * Update Date: 2024/03/29
 * Description: This program is to list and initialize the class form
***********************************************************************/

#include<string>
#include<iostream>
#include<fstream>
#include<vector>

class Form
{
private:
	std::string answer;
	std::string file;
	std::string words;
	std::vector<std::string> matches;
public:
	void SetInputWord(std::string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(std::string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
