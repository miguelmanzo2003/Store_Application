#include <iostream>
#include "Node.h"
#include "Item.h"

using namespace std;

Node::Node(Item* nodeItem){
    this->nodeItem = nodeItem;
    this->prev = nullptr;
    this->next = nullptr;
}

//prev methods
void Node::setPrev(Node* prevItem) {
    this->prev = prevItem;
}

Node* Node::getPrev() const {
    return this->prev;
}

//next methods
void Node::setNext(Node* nextItem) {
    this->next = nextItem;
}

Node* Node::getNext() const {
    return this->next;
}

void Node::printContent(){
    nodeItem->displayItem();
}

Item* Node::getItem() const{
    return this->nodeItem;
}
