/***********************************************************************
 * File: Template.h
 * Author: B11215002
 * Create Date: 2024/5/15
 * Editor: B11215002
 * Update Date: 2024/5/20
 * Description: This program is to run the calculation and return it's result in absolute value
***********************************************************************/

#pragma once
template <class num>

double absoluteValue(num& input1, num& input2){
	double result = input1 - input2;
	if (result > 0)
		return result;
	else
		return -result;
}
