#include <iostream>
#include "LinkedList.h"
#include "Node.h"

#include <string>
using namespace std;

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;

}

LinkedList::~LinkedList() {

    Node* currNode = head;
    while (currNode != nullptr) {
        Node* deletePtr = currNode;
        currNode = currNode->getNext();
        delete deletePtr;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
}

void LinkedList::pushBack(Node* newItem) {
    if (tail == nullptr) {
        head = newItem;
        tail = newItem;
    }
    else {
        this->tail->setNext(newItem);
        newItem->setPrev(tail);
        this->tail = newItem;

    }
    listSize++;
}

//head methods
Node* LinkedList::getHead() const {
    return this->head;
}

void LinkedList::setHead(Node* head) {
    this->head = head;
}

//tail methods
Node* LinkedList::getTail() const {
    return this->tail;
}

void LinkedList::setTail(Node* tail) {
    this->tail = tail;
}














