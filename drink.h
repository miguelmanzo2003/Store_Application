#pragma once
#ifndef DRINK_H
#define DRINK_H

#include "Item.h"

#include <string>
using namespace std;

struct drink : public Item {
private:
    bool isRecyclable;
    bool isAlcoholic;
    int sizeOz;

public:

    drink(string itemName, int inventory, int idNum, double itemPrice, bool isRecycable, bool isAlchoholic, int sizeOz);

    drink(const drink& drinkCopy);

    void displayItem() const override;

    Item* cloneItem() const override;
};
#endif 
