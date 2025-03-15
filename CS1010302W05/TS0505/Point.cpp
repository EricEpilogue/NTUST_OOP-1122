/***********************************************************************
 * File: Point.cpp
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to set functions that can modify a point (x,y)
***********************************************************************/

#include "Point.h"

// Intent: To reflect a point by the origin
// Pre: just x and y
// Post: (x,y) = (-x, -y)
void Point::Reflect() {
	this->horizontal *= -1;
	this->vertical *= -1;
}

// Intent: To set the x as vertical, y as horizontal
// Pre: undefined and not initialized
// Post: (x,y) = (vertical, horizontal)
void Point::Set(int horizontal, int vertical)
{
	this->horizontal = horizontal;
	this->vertical = vertical;
}

// Intent: Move the point by x and y
// Pre: unchanged
// Post: (vertical, horizontal) = (vertical + x, horizontal + y)
void Point::Move(int y, int x)
{
	this->horizontal += y;
	this->vertical += x;
}

// Intent: Rotate the point by 90 degrees
// Pre: unchanged
// Post: (vertical, horizontal) = (horizontal, -vertical)
void Point::Rotate()
{
	int temp = this->vertical; //y
	this->vertical = -(this->horizontal); //y = -x
	this->horizontal = temp; //x = y
}

// Intent: To reset x and y
// Pre: could cause memory leak by changing values
// Post: reset coordinates to (x,y) = (0, 0)
void Point::deconstructor() {
	this->horizontal = 0;
	this->vertical = 0;
}