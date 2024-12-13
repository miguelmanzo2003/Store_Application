#pragma once
#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include <fstream>
#include "Aisle.h"
#include "Item.h"
#include "food.h"
#include "drink.h"
#include "guest.h"

using namespace std;

struct store {
private:
    string storeName;

    int numOfAisle;

    enum options {
        AILSE = 1, HOURS, CART, REMOVE, CHECKOUT
    };

    int currentAisle = 1;

    string ListOfAisles = "AisleList.txt";
    string ListOfItems = "itemsList.txt";

    vector<Aisle> aisleList;

    guest user = guest();

    Aisle produce = Aisle("Produce");
    Aisle drinks = Aisle("Drinks");
//produce items
    food* apples;
    food* banana;
    food* carrot;
    food* orange;
    food* tomato;
//drinks items
    drink* water;

    Node* item1;
    Node* item2;
    Node* item3;
    Node* item4;
    Node* item5;
    Node* item6;

    void initializeAisles();

public:

    store(string storeName, int NumOfAisle);

    int getMenuChoice();

    string getStoreName();

    void printStoreHrs();

    void enterAisleMenu();

    void printAisleList();



};

#endif 