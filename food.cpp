#include <iostream>
#include "food.h"
#include "Item.h"
#include <string>

using namespace std;

food::food(string itemName, int inventory, int idNum, double itemPrice, int calories, string expiration) :Item(itemName, inventory,idNum, itemPrice) {
	this->setWord(itemName);
	this->setInventory(inventory);
	this->setIdNum(idNum);
	this->setItemPrice(itemPrice);
	this->calories = calories;
	this->expiration = expiration;
	this->setPrev(nullptr);
	this->setNext(nullptr);
}

food::food(const food& foodCopy):Item(foodCopy){
	this->setWord(foodCopy.getWord());
	this->setInventory(foodCopy.getInventory());
	this->setIdNum(foodCopy.getIdNum());
	this->setItemPrice(foodCopy.getItemPrice());
	
	this->calories = foodCopy.calories;
	this->expiration = foodCopy.expiration;
	this->setPrev(nullptr);
	this->setNext(nullptr);
}

void food::displayItem() const {
	cout << this->getWord() << ": Stock: " << this->getInventory() << ", Calories " << this->calories << ", Expires on " << this->expiration << ", Price: " << this->getItemPrice() << "$. ID# " << this->getIdNum() << endl;
}

Item* food::cloneItem() const{
	return new food(*this);
}


