#include <iostream>
#include "drink.h"
#include "Item.h"
#include <string>

using namespace std;

drink::drink(string itemName, int inventory, int idNum, double itemPrice, bool isRecyclable, bool isAlcoholic, int sizeOz) :Item(itemName, inventory, idNum, itemPrice) {
    this->setWord(itemName);
    this->setInventory(inventory);
    this->setIdNum(idNum);
    this->setItemPrice(itemPrice);
    this->isRecyclable = isRecyclable;
    this->isAlcoholic = isAlcoholic;
    this->sizeOz = sizeOz;
}

drink::drink(const drink& drinkCopy):Item(drinkCopy){
    this->isRecyclable = drinkCopy.isRecyclable;
    this->isAlcoholic = drinkCopy.isAlcoholic;
    this->sizeOz = drinkCopy.sizeOz;
}

void drink::displayItem()const {
    string bool1;
    string bool2;
    if (this->isAlcoholic == true) {
        bool1 = "Drink is alcoholic, ";
    }
    else {
        bool1 = "Drink is not alcoholic, ";
    }
    if (this->isRecyclable == true) {
        bool2 = "Drink is Recyclable";
    }
    else {
        bool2 = "Drink is Not recyclable";
    }
    cout << this->getWord() << ": Stock: " << this->getInventory() << ", " << bool1 << bool2 << ", Drink is " << this->sizeOz << " ounces, Price: " << this->getItemPrice() << "$. ID# " << this->getIdNum() << endl;
}

Item* drink::cloneItem() const{
    return new drink(*this);
}
