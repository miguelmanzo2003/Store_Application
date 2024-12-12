#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(string itemName, int inventory, int idNum, double itemPrice) {
	this->itemName = itemName;
	this->inventory = inventory;
	this->idNum = idNum;
	this->itemPrice = itemPrice;

	this->prev = nullptr;
	this->next = nullptr;

}

Item::Item(const Item& copy){
	this->itemName = copy.getWord();
	this->inventory = copy.getInventory();
	this->idNum = copy.getIdNum();
	this->itemPrice = copy.getItemPrice();

	this->prev = nullptr;
	this->next = nullptr;
}


string Item::getWord() const{
	return itemName;
}

void Item::setWord(string itemName){
	this->itemName = itemName;
}

int Item::getIdNum() const{
	return idNum;
}

void Item::setIdNum(int idNum){
	this->idNum = idNum;
}

int Item::getInventory() const{
	return inventory;
}

void Item::setInventory(int inventory){
	this->inventory = inventory;
}

double Item::getItemPrice() const{
	return itemPrice;
}

void Item::setItemPrice(double itemPrice){
	this->itemPrice = itemPrice;
}

//prev methods
void Item::setPrev(Item* prevItem){
	this->prev = prevItem;
}

Item* Item::getPrev() const{
	return this->prev;
}

//next methods
void Item::setNext(Item* nextItem){
	this->next = nextItem;
}

Item* Item::getNext() const{
	return this->next;
}



