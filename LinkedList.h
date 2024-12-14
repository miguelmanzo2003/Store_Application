#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


#include <string>
using namespace std;

struct LinkedList {
private:
    Node* head;
    Node* tail;
    int listSize;

public:

    LinkedList();

    ~LinkedList();

    void pushBack(Node* Item);

    int size() const;

    Node *  insert_before(Node* newItem, Node * knownNode);

    void removeFromFront();

//head methods
    Node* getHead() const;

    void setHead(Node* head);

//tail methods
    Node* getTail() const;

    void setTail(Node* tail);


};

#endif
