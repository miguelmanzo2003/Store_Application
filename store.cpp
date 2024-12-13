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

    //this code will be deleted later
    this->apples = new food("Apples: One Dozen (12)", 100, 50, 1.80, 924, "December 24, 2024");
    this->banana = new food("Banana: Pack of 5", 100, 49, 1.75, 525, "December 24, 2024");
    this->orange = new food("Oranges: Pack of 10", 100, 46, 7.50, 620, "December 24, 2024");
    this->carrot = new food("Carrots: Pack of 10", 100, 48, 2.00, 250, "December 31, 2024");
    this->tomato = new food("Tomatoes: Pack of 10", 100, 47, 2.00, 220, "December 24, 2024");
    this->water = new drink("Bottle of water", 50, 40, 1.50, true, false, 20);
    // ---------------------------------------------------------------------------------------

    initializeAisles();
}

void store::initializeAisles(){
    //this will also be replaced
    aisleList.push_back(produce);
    aisleList.push_back(drinks);

    aisleList.at(0).pushBack(apples);
    aisleList.at(0).pushBack(banana);
    aisleList.at(0).pushBack(carrot);
    aisleList.at(0).pushBack(tomato);
    aisleList.at(0).pushBack(orange);
    aisleList.at(1).pushBack(water);
    //-------------------------------
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


            produce.~Aisle();
            drinks.~Aisle();

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
    for (int i = 0; i < 2; i++) {
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

