/***********************************************************************
 * File: PrintCombination.h
 * Author: B11215002
 * Create Date: 2024/4/29
 * Editor: B11215002
 * Update Date: 2024/4/29
 * Description: This program is to find all possible combinations from given number
***********************************************************************/

#pragma once
#include <iostream>
#include <vector>

void combination(int arr[], std::vector<int> data, int start, int end, int index, int r);
    
// Intent: exists just to call a function with more parameters to use
// Pre: receives the array and numbers
// Post: calls for the combination function for recursively finding the result
void PrintCombination(int *array, int upper, int under) {
	std::vector<int> temp;
    combination(array, temp, 0, upper - 1, 0, under);
}

// Intent: recursively finding the possible combination
// Pre: nothing
// Post: prints all combinations without duplication
void combination(int arr[], std::vector<int> data, int start, int end, int index, int endPoint) {
    data.resize(end + 1);
    //if the index for combinations formed matches the required size, print and return
    if (index == endPoint) {
        for (int i = 0; i < endPoint; i++) {
            if (i != endPoint - 1)
                std::cout << data[i] << " ";
            //avoid extra spaces as required
            else
                std::cout << data[i];
        }
        std::cout << "\n";
        return;
    }
    else {
        //two stop cases, loop through the sizes and loop through the remaining yet to find
        for (int i = start; i <= end && end - i + 1 >= endPoint - index; i++){
            data[index] = arr[i];
            combination(arr, data, i + 1, end, index + 1, endPoint);
        }
    }
}

