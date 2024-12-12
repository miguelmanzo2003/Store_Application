#pragma once
#ifndef AISLE_H
#define AISLE_H

#include "Item.h"
#include "food.h"
#include "drink.h"

#include <string>
using namespace std;

struct Aisle {
private:
	string aisleName;
	int aisleNum;
	Item* head;
	Item* tail;

public:
	Aisle(string aisleName);

	Aisle();

	~Aisle();

	void pushBack(Item* Item);

	//aisle methods
	string getAisleName() const;


	//size methods
	int getAisleNum() const;

	void setAisleNum(int length);


	//head methods
	Item* getHead() const;

	void setHead(Item* head);

	//tail methods
	Item* getTail() const;

	void setTail(Item* tail);

	//print
	void printToScreen();





};

#endif