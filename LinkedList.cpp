#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    size = 0;
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList& other) //This is to copy the list passed in
{
    size = other.size;
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        head = new Node(other.head->coef, other.head->exp);
        Node* current = head;
        Node* otherCurrent = other.head->next;
        while (otherCurrent != nullptr) {
            current->next = new Node(otherCurrent->coef, otherCurrent->exp);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}
LinkedList::~LinkedList() {
    recursiveDelete(head);
}

void LinkedList::recursiveDelete(Node* node) {
    if (node != nullptr) {
        recursiveDelete(node->next);
        delete node;
    }
}

Node* LinkedList::getHead() const {
    return head;
}

void LinkedList::setHead(const LinkedList& other) {
    recursiveDelete(head);
    head = copyList(other.head);
    size = other.size;
}

Node* LinkedList::copyList(Node* sourceHead) {
    if (sourceHead == nullptr) {
        return nullptr;
    }
    Node* newNode = new Node(sourceHead->getCoef(), sourceHead->getExp());
    newNode->setNext(copyList(sourceHead->getNext()));
    return newNode;
}

void LinkedList::sortList() {
    if (size <= 1) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;
        Node* nextNode = current->next;

        for (int i = 0; i < size - 1; ++i) {
            if (current->exp < nextNode->exp) {
                // Swap the node positions
                current->next = nextNode->next;
                nextNode->next = current;
                if (prev == nullptr) {
                    head = nextNode;
                } else {
                    prev->next = nextNode;
                }
                prev = nextNode;
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
            if (current != nullptr) {
                nextNode = current->next;
            }
        }
    } while (swapped);
}

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->exp << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

