#pragma once
#ifndef GUEST_H
#define GUEST_H

#include <string>
#include "Aisle.h"
#include "Item.h"
#include "food.h"
#include "drink.h"

using namespace std;

struct guest {
private:
    double userBudget;
    double total;

    LinkedList userCart = LinkedList();
public:
    guest();

    double generateBudget();

    void addToCart(LinkedList& ailseList, int idNum);

    void removeItem(int idNum);

    double getUserBudget()const;

    void printItems();

    void deleteUserCart();



    double getTotal() const;

};


#endif 
