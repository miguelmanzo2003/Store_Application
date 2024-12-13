#include <iostream>
#include "item.h"
#include "food.h"
#include "drink.h"
#include "Aisle.h"

using namespace std;

Aisle::Aisle(string aisleName) {
    this->aisleNum = 0;
    this->aisleName = aisleName;

}

void Aisle::deleteAisle(){
    aisleItems.~LinkedList();
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


void Aisle::printToScreen() {
    Node* currNode = aisleItems.getHead();

    while (currNode != nullptr) {
        currNode->printContent();
        currNode = currNode->getNext();
    }
}

LinkedList& Aisle::getList(){
    return this->aisleItems;
}

void Aisle::setAisle(LinkedList aisleItems){
    this->aisleItems = aisleItems;
}