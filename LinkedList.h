#pragma once
#include "Node.h"

class LinkedList {
public:
    Node* head;
    int size;

    // Default constructor
    LinkedList();

    // Overloaded constructor
    LinkedList(const LinkedList& other);

    // Destructor
    ~LinkedList();

    // Helper function for recursive destructor
    void recursiveDelete(Node* node);

    // Accessors and mutators
    Node* getHead() const;
    void setHead(const LinkedList& other);

    // Sort method
    void sortList();

    // Display method
    void display() const;

private:
    Node* copyList(Node* sourceHead);
};
