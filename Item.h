#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

struct Item {
private:
	string itemName;
	int inventory;
	int idNum;
	double itemPrice;
	Item* prev;
	Item* next;

public:
	
	Item(string itemName, int inventory, int idNum, double itemPrice);
	
	Item(const Item& copy);
	
	//Display
	virtual void displayItem() const = 0;

	virtual Item* cloneItem() const = 0;


	//Getter and Setter methods
	
	// item name
	string getWord()const; 

	void setWord(string itemName); 
	
	// id num
	int getIdNum()const; 

	void setIdNum(int idNum); 
	
	// inventory size
	int getInventory()const; 

	void setInventory(int idNum);

	// item price
	double getItemPrice()const; 

	void setItemPrice(double itemPrice);

	//prev methods
	void setPrev(Item* prevItem);

	Item* getPrev() const;

	//next methods
	void setNext(Item* nextItem);

	Item* getNext() const;

	

};

#endif