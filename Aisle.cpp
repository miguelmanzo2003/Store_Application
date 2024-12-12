#include <iostream>
#include "item.h"
#include "food.h"
#include "drink.h"
#include "Aisle.h"

using namespace std;

Aisle::Aisle(string aisleName) {
	this->head = nullptr;
	this->tail = nullptr;
	this->aisleNum = 0;
	this->aisleName = aisleName;
}

Aisle::Aisle(){
	this->head = nullptr;
	this->tail = nullptr;
}

Aisle::~Aisle() {
	Item* currNode = head;
	while (currNode != nullptr) {
		Item* deletePtr = currNode;
		currNode = currNode->getNext();
		delete deletePtr;
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->aisleNum = 0;
}

void Aisle::pushBack(Item* newItem) {
	if (tail == nullptr) {
		head = newItem;
		tail = newItem;
	}
	else {
		this->tail->setNext(newItem);
		newItem->setPrev(tail);
		this->tail = newItem;

	}
	aisleNum++;
}

string Aisle::getAisleName() const{
	return this->aisleName;
}

//aisle methods
int Aisle::getAisleNum() const {
	return this->aisleNum;
}

void Aisle::setAisleNum(int length) {
	this->aisleNum = aisleNum;
}

//head methods
Item* Aisle::getHead() const {
	return this->head;
}

void Aisle::setHead(Item* head) {
	this->head = head;
}

//tail methods
Item* Aisle::getTail() const {
	return this->tail;
}

void Aisle::setTail(Item* tail) {
	this->tail = tail;
}

void Aisle::printToScreen() {
	Item* currNode = head;

	while (currNode != nullptr) {
		currNode->displayItem();
		currNode = currNode->getNext();
	}
}