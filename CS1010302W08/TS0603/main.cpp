/***********************************************************************
 * File: main.cpp
 * Author: B11215002
 * Create Date: 2024/4/12
 * Editor: B11215002
 * Update Date: 2024/4/12
 * Description: This program is to test NumberGame.h, will be replaced by OJ
***********************************************************************/

#include <iostream>
#include "NumberGame.h"

int main() {
	NumberGame Game;
	Game.SetInput(6886);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();

	Game.Reset();
	std::cout << "\n";
	Game.SetInput(2345);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();
}
