/***********************************************************************
 * File: main.cpp
 * Author: B11215002
 * Create Date: 2024/03/28
 * Editor: B11215002
 * Update Date: 2024/03/29
 * Description: This program is subjected to change in the OJ
***********************************************************************/
//FormWord-inputmain1.cpp
#include"Form.h"

int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING"); // set input
	form1.ProcessInputWord(); // process input
	form1.SetFileName("words.txt"); // set file name
	form1.Load_CompareWord(); // read-in data and compare
	form1.PrintFoundWords(); // print answers
	return 0;
}