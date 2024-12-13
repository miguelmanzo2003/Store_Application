#include <iostream>
#include <string>
#include "Aisle.h"
#include "Item.h"
#include "food.h"
#include "drink.h"
#include "guest.h"

using namespace std;

guest::guest() {
    this->total = 0.0;
    this->userBudget = generateBudget();


}

double guest::generateBudget() {
    srand(static_cast<unsigned int>(time(0)));
    double randomValue = 80.0 + (rand() % 1001) / 100.0;
    cout.precision(2);
    return randomValue;

}

void guest::addToCart(LinkedList& aisleList, int idNum){

    Node* currItem = aisleList.getHead();

    while (currItem != nullptr) {
        if (idNum == currItem->getItem()->getIdNum()) {

            Item* copyItem = currItem->getItem()->cloneItem();
            userCart.pushBack(new Node (copyItem));

            int newInventory = currItem->getItem()->getInventory() - 1; // set new inventory
            currItem->getItem()->setInventory(newInventory);
            double itemPrice = currItem->getItem()->getItemPrice();
            this->total = this->total + itemPrice;

            currItem = currItem->getNext();
            return;
        }
        else {
            currItem = currItem->getNext();
        }
    }

    cout << "Could not find your Item" << endl;
    cout << endl;

}

double guest::getUserBudget() const
{
    return this->userBudget;
}

void guest::printItems(){
    Node* currItem = userCart.getHead();
    if (currItem == nullptr) {
        cout << "Cart is empty" << endl;
        return;
    }
    while (currItem != nullptr) {
        cout << currItem->getItem()->getWord() << " Price: " << currItem->getItem()->getItemPrice() << " ID# " << currItem->getItem()->getIdNum() << endl;
        currItem = currItem->getNext();
    }
}

void guest::deleteUserCart(){
    userCart.~LinkedList();
}

double guest::getTotal() const
{
    return this->total;
}

void guest::removeItem(int id){
    Node* currItem = userCart.getHead();
    if (currItem == nullptr)
    {
        cout << "Cart is empty" << endl;
        return;
    }
    while (currItem != nullptr)
    {
        if (id == currItem->getItem()->getIdNum())
        {
            this->total = this->total - currItem->getItem()->getItemPrice();
            if (currItem == userCart.getHead())
            {
                userCart.setHead(currItem->getNext());
                if (userCart.getHead() != nullptr)
                {
                    userCart.getHead()->setPrev(nullptr);
                }
            }
            else
            {
                currItem->getPrev()->setNext(currItem->getNext());
                if (currItem->getNext() != nullptr)
                {
                    currItem->getNext()->setPrev(currItem->getPrev());
                }
            }
            delete currItem;
            return;
        }
    }
    cout << "Item not found in cart" << endl;
}

