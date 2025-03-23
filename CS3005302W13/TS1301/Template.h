/***********************************************************************
 * File: Template.h
 * Author: B11215002
 * Create Date: 2024/5/15
 * Editor: B11215002
 * Update Date: 2024/5/20
 * Description: This program the binary search algorithm implemented in both iterative and recursive
***********************************************************************/

#pragma once
#include <iostream>
#include <string>
template<class T>

// Intent: To run binary search through a sorted array
// Pre: enter a sorted array and search the intented element
// Post: The function returns true or false and where it is
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location){
	//initiate the found status as false
	found = false;
	//stop condition
	while (last >= first) {
		int middle = first + (last - first) / 2;
		//found
		if (a[middle] == key) {
			location = middle;
			found = true;
			return;
		}
		if (a[middle] < key) {
			first = middle + 1;
		}
		if (a[middle] > key) {
			last = middle - 1;
		}
	}

	return;
}

template<class T>

// Intent: To run binary search through a sorted array
// Pre: enter a sorted array and search the intented element
// Post: The function returns true or false and where it is
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location){
	//initiate the found status as false
	found = false;
	if (last >= first) {
		int middle = (first + last) / 2;
		//found
		if (a[middle] == key) {
			location = middle;
			found = true;
			return;
		}
		if (a[middle] < key) {
			middle = (first + middle) / 2;
			RecBinarySearch(a, middle + 1, last, key, found, location);
		}
		if (a[middle] > key) {
			middle = (last + middle) / 2;
			RecBinarySearch(a, first, middle - 1, key, found, location);
		}
	}

	return;
}
