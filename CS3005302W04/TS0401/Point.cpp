#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	this->horizontal = horizontal;
	this->vertical = vertical;
}

void Point::Move(int x, int y)
{
	this->horizontal += y;
	this->vertical += x;
}

void Point::Rotate()
{
	int temp = this->horizontal;
	this->horizontal = -(this->vertical);
	this->vertical = temp;
}