/***********************************************************************
 * File: Point.h
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to set functions prototypes and intialize variables
***********************************************************************/

#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point
{
private:
	int vertical;
	int horizontal;

public:
	Point()
	{
		vertical = 0;
		horizontal = 0;
	}

	void Set(int vertical, int horizontal); //To set the x as vertical, y as horizontal
	void Move(int x, int y); //Move the point by x and y
	void Rotate(); //Rotate the point by 90 degrees
	void Reflect(); //Reflect with 0,0
	void deconstructor(); //Avoiding memory leak
	int GetVertical() const { return vertical; } //Return the value of vertical 
	int GetHorizontal() const { return horizontal; } //Return the value of horizontal
};

#endif //Point_H