/***********************************************************************
 * File: HotDogStand.cpp
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to design functions that calculate how many hot dogs have been sold
***********************************************************************/

#include "HotDogStand.h"
#include <iostream>

int HotDogStand::totalSellAmount = 0;

// Intent: default constructor
HotDogStand::HotDogStand()
{
	this->hotDogSellAmount = 0;
	this->totalSellAmount = 0;
}

// Intent: default constructor with only shop ID
HotDogStand::HotDogStand(const char *id)
{	
	this->standId = id;
	this->hotDogSellAmount += 0;
	this->totalSellAmount += 0;
}

// Intent: input constructor with shop ID and sold amount
HotDogStand::HotDogStand(const char * id, int amount)
{
	this->standId = id;
	this->hotDogSellAmount += amount;
	this->totalSellAmount += amount;
}

// Intent: Stand copy
HotDogStand::~HotDogStand()
{
}

// Intent: To add by 1 each time a hot dog stand sold a hotdog
// Pre: unchanged
// Post: amount of hod dog sold by this shop and by total increased by 1
void HotDogStand::justSold()
{
	this->hotDogSellAmount += 1; 
	this->totalSellAmount += 1;
}


// Intent: Print out how many hotdogs have been sold
// Pre: no input
// Post: print by the format of "Shop ID" and "How many have been sold"
void HotDogStand::print()
{
	std::cout << this->standId << " " << this->hotDogSellAmount << std::endl;
}

// Intent: return out how many hotdogs have been sold by one shop partcularly
// Pre: no input
// Post: return the amount of hot dog sold
int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount;
}

// Intent: return how many hotdogs have been sold totally only
// Pre: no input
// Post: return the amount of hot dog sold by every shot combined
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
