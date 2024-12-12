#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "Item.h"

#include <string>
using namespace std;

struct food : public Item {
private:
	int calories;
	string expiration;

public:
	food(string itemName, int inventory, int idNum, double itemPrice, int calories, string expiration);

	food(const food& foodCopy);

	void displayItem() const override;

	Item* cloneItem() const override;
	
	
};

#endif 
