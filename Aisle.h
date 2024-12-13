#pragma once
#ifndef AISLE_H
#define AISLE_H

#include "LinkedList.h"
#include "Item.h"
#include "food.h"
#include "drink.h"


#include <string>
using namespace std;

struct Aisle {
private:
    string aisleName;
    int aisleNum;

    LinkedList aisleItems = LinkedList();


public:
    Aisle(string aisleName);

    void deleteAisle();

//aisle methods
    string getAisleName() const;


//size methods
    int getAisleNum() const;

    void setAisleNum(int length);

//print
    void printToScreen();

    LinkedList& getList();

    void setAisle(LinkedList aislelItems);



};

#endif