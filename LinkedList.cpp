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

int LinkedList::size() const{
    return this->listSize;
}

Node *  LinkedList::insert_before(Node* newItem, Node * knownNode){


    Node* newNode = newItem;

    if(knownNode->getPrev() == nullptr){
        head = newNode;
        head->setNext(knownNode);
        knownNode->setPrev(head);

        this->listSize = listSize + 1;

        return newNode;
    }

    newNode->setPrev(knownNode->getPrev());
    knownNode->getPrev()->setNext(newNode);
    newNode->setNext(knownNode);
    knownNode->setPrev( newNode);

    this->listSize = listSize + 1;

    return newNode;
}


void LinkedList::removeFromFront(){


    if(this->head != nullptr && this->head->getNext() != nullptr){
        this->head = this->head->getNext();
        this->head->setPrev(nullptr);
        this->listSize = listSize - 1;
    }else if(this->head != nullptr && this->head->getNext() == nullptr){
        this->head = nullptr;
        this->listSize = 0;
    }
}
















