#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>
#include "Item.h"
using namespace std;

struct Node {
private:
    Node* prev;
    Node* next;

    Item* nodeItem;

public:

    Node(Item* nodeItem);

//prev methods
    void setPrev(Node* prevItem);

    Node* getPrev() const;

//next methods
    void setNext(Node* nextItem);

    Node* getNext() const;

    void printContent();

    Item* getItem() const;



};


#endif // Node