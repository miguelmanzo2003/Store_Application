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

void guest::addToCart(Aisle& aisleList, int idNum){

	Item* currItem = aisleList.getHead();

	while (currItem != nullptr) {
		if (idNum == currItem->getIdNum()) {
			
			Item* copyItem = currItem->cloneItem();
			userCart.pushBack(copyItem);

			int newInventory = currItem->getInventory() - 1; // set new inventory
			currItem->setInventory(newInventory);
			double itemPrice = currItem->getItemPrice();
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
	Item* currItem = userCart.getHead();
	if (currItem == nullptr) {
		cout << "Cart is empty" << endl;
		return;
	}
	while (currItem != nullptr) {
		cout << currItem->getWord() << " Price: " << currItem->getItemPrice() << " ID# " << currItem->getIdNum() << endl;
		currItem = currItem->getNext();
	}
}

void guest::deleteUserCart(){
	userCart.~Aisle();
}

void guest::removeItem(int id){
	Item* currItem = userCart.getHead();
	if (currItem == nullptr)
	{
		cout << "Cart is empty" << endl;
		return;
	}
	while (currItem != nullptr)
	{
		if (id == currItem->getIdNum())
		{
			this->total = this->total - currItem->getItemPrice();
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

