#include <iostream>
#include <vector>
#include <fstream>
#include "store.h"
#include "Aisle.h"
#include "Item.h"
#include "food.h"
#include "drink.h"

using namespace std;

store::store(string storeName, int numOfAisle) {
	this->storeName = storeName;
	this->numOfAisle = numOfAisle;
	initializeAisles();
}

void store::initializeAisles(){

	ifstream inFS;
	ifstream items;
	string word;
	string itemVar;
	inFS.open(ListOfAisles);

	if (!inFS.is_open()) {
		cout << "ERROR! Cannot read file" << endl;
	}
	while (getline(inFS, word)) {
		aisleList.push_back(Aisle(word));
	}

	inFS.close();

	items.open(ListOfItems);

	if (!items.is_open()) {
		cout << "ERROR! Cannot read file" << endl;
	}

	string name;
	int inv;
	int ID;
	double price;
	int  cal;
	string ex;
	bool al;
	bool re;
	int oz;

	int con;

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5;i++) {
			items >> itemVar;
			if (itemVar == "food") {
				items.ignore();
				getline(items, name);

				items >> inv;

				items >> ID;

				items >> price;

				items >> cal;
				items.ignore();
				getline(items, ex);

				aisleList.at(j).pushBack(new food(name, inv, ID, price, cal, ex));

			}
			else if (itemVar == "drink") {

				items.ignore();
				getline(items, name);

				items >> inv;

				items >> ID;

				items >> price;

				items >> con;
				if (con == 1) {
					re = true;
				}
				else {
					re = false;
				}

				items >> con;
				if (con == 1) {
					al = true;
				}
				else {
					al = false;
				}

				items >> oz;
				aisleList.at(j).pushBack(new drink(name, inv, ID, price, re, al, oz));
			}

		}
	}

	items.close();	
}

int store::getMenuChoice() {

	

	cout << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Welcome to " << this->getStoreName() << "." << endl;
	cout << "Options menu: " << endl;
	cout << "(" << AILSE << ") Enter the current Aisle: #" << currentAisle << endl;
	cout << "(" << HOURS << ") Look at the store hours" << endl;
	cout << "(" << CART << ") Look at items in the cart" << endl;
	cout << "(" << REMOVE << ") Remove an item from your cart" << endl;
	cout << "(" << CHECKOUT << ") Checkout and pay to exit store" << endl;
	cout << "Enter a number from 1 to 4, or 5 to checkout: ";

	int userChoice; // get user choice
	cin >> userChoice;

	cout << endl;

	if (userChoice > 5 || userChoice < 1) {
		cout << "Error! Input must be a number between 1 and 4, or 0 to Checkout." << endl;
		cout << endl;
		userChoice = 6;
	}

	switch (userChoice) {
	case AILSE:
		this->enterAisleMenu();
		
		break;
	case HOURS:
		this->printStoreHrs();
		break;
	case CART:
		user.printItems();
		break;
	case REMOVE:
		int userID;
		cin >> userID;
		user.removeItem(userID);
		cout << "coming soon" << endl;

		break;
	case CHECKOUT:

		cout << "coming soon" << endl;
		
		user.deleteUserCart();

		for(int i = 0; i < 5; i++){
		aisleList.at(i).~Aisle();}
		return 1;
	}


	getMenuChoice();


}

string store::getStoreName() {
	return this->storeName;
	
}

void store::printStoreHrs() {
	cout << this->getStoreName() << " store Hours:" << endl;
	cout << "Monday: 6 AM-11PM" << endl;
	cout << "Tuesday: 6 AM-11PM" << endl;
	cout << "Wednesday: 6 AM-11PM" << endl;
	cout << "Thursday: 6 AM-11PM" << endl;
	cout << "Friday: 6 AM-11PM" << endl;
	cout << "Saturday: 6 AM-10PM" << endl;
	cout << "Sunday: 6 AM-10PM" << endl;
}

void store::enterAisleMenu() {
	cout << "Welcome to " << aisleList.at(currentAisle-1).getAisleName() <<  " Aisle:" << endl;
	cout << "Here are the Items available" << endl;
	cout << "Your budget is " << user.getUserBudget() << "$" << endl;
	cout << "--------------------------------------------" << endl;
	aisleList.at(currentAisle-1).printToScreen();
	cout << "--------------------------------------------" << endl;
	cout << "Options menu: " << endl;
	cout << "(1) Add item to cart" << endl;
	cout << "(2) Remove item from cart" << endl;
	cout << "(3) Sort AisleList" << endl;
	cout << "(4) Go to another Aisle:" << endl;
	cout << "Enter a number from 1 to 4, or 5 to go back: ";
	int menu2Choice;
	cin >> menu2Choice;

	cout << endl;

	if (menu2Choice > 5 || menu2Choice < 1) {
		cout << "Error! Input must be a number between 1 and 4, or 5 to go back." << endl;
		cout << endl;
		menu2Choice = 6;
	}

	switch (menu2Choice) {
	case 1:
		int userId;
		cout << "Enter the ID of the item you want to add:";
		cin >> userId;
		cout << endl;

		user.addToCart(aisleList[currentAisle - 1], userId);
		

		break;
	case 2:
		cout << "coming soon" << endl;
		break;

	case 3:
		cout << "coming soon" << endl;
		break;

	case 4:
		this->printAisleList();
		break;
	case 5:
		return;
		break;



	}

	enterAisleMenu();

}

void store::printAisleList(){
	cout << "Pick from the following Aisle Options :" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "(" << i + 1 << ") " << aisleList.at(i).getAisleName() << endl;
	}
	cout << "Enter a number from 1 to 5: ";
	int aisleChoice;
	cin >> aisleChoice;

	if (aisleChoice > 5 || aisleChoice < 1) {
		cout << "Error! Input must be a number between 1 and 5" << endl;
		cout << endl;
		printAisleList();
	}

	currentAisle = aisleChoice;


}

