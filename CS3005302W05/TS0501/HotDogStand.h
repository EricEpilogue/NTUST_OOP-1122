/***********************************************************************
 * File: HotDogStand.h
 * Author: B11215002
 * Create Date: 2024/03/22
 * Editor: B11215002
 * Update Date: 2023/03/24
 * Description: This program is to set function prototypes
***********************************************************************/

#pragma once
class HotDogStand
{
private:
	const char* standId;
	int hotDogSellAmount = 0;
	static int totalSellAmount;
public:
	HotDogStand(); //default constructor
	HotDogStand(const char *id); //input constructor with only shop ID
	HotDogStand(const char *id, int amount); //input constructor with shop ID and sold amount
	~HotDogStand(); //copy constructor
	void justSold(); //get how many hotdogs are sold and add it to the total amount
	void print(); //print how many hotdogs have been sold
	int thisStandSoldAmount(); //print how many hotdogs have been sold by this shop particularly
	static int allStandSoldAmount(); //print how many hotdogs have been sold totally only
};
