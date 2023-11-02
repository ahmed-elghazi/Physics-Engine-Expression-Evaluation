#include <iostream>
#include "LinkedList.h"

int main() {
// Manually create a linked list with 5 nodes
    LinkedList list1;

    Node* node1 = new Node(1.0, 5);
    Node* node2 = new Node(3.5, 2);
    Node* node3 = new Node(2.2, 8);
    Node* node4 = new Node(4.1, 1);
    Node* node5 = new Node(0.9, 4);

    node1->setNext(node2);
    node2->setNext(node3);
    node3->setNext(node4);
    node4->setNext(node5);

    list1.head = node1; // pass the list through to copy and sort that one
    list1.size = 5;

    // Create a second linked list using an overloaded constructor
    LinkedList list2(list1);

    // Call the sort function on the second linked list
    list2.sortList();

    // Display both linked lists
    std::cout << "Original list (unsorted):" << std::endl;
    list1.display();

    std::cout << "Copied list (sorted):" << std::endl;
    list2.display();

    return 0;
}
