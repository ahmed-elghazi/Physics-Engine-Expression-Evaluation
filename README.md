# Physics Engine Expression Evaluation

This project contains a basic implementation of a singly linked list in C++. The linked list is composed of nodes that store data and a pointer to the next node in the list. The project includes the following files:

## Files

- **main.cpp**: This file contains the main function and serves as the origin for the program. It demonstrates the usage of the linked list by performing various operations such as insertion, deletion, and traversal.

- **Node.h**: This header file defines the structure of a node in the linked list. Each node contains a data field and a pointer to the next node in the list.

- **Node.cpp**: This source file implements the functions associated with the `Node` class, including constructors and possibly other utility functions.

- **LinkedList.h**: This header file defines the `LinkedList` class, which manages the nodes in the list. It declares various methods for manipulating the list, such as adding or removing nodes, searching for elements, and printing the list.

- **LinkedList.cpp**: This source file implements the methods declared in `LinkedList.h`. It provides the logic for adding, removing, and traversing the nodes in the linked list.

## Features

- **Insertion**: Add new nodes to the list at the beginning, end, or any specified position.
- **Deletion**: Remove nodes from the list based on their position or value.
- **Traversal**: Traverse and print the contents of the list.
- **Search**: Search for specific values in the list.

## Polynomial Evaluation

This project can also be used to evaluate polynomial expressions. The polynomial is represented as a linked list where each node stores:

- **coefficient**: The multiplier of the term (e.g., 3 in \(3x^2\)).
- **exponent**: The power to which the variable (usually x) is raised (e.g., 2 in \(3x^2\)).

### How Polynomial Evaluation Works:

1. **Representation**: Each term in the polynomial is stored as a node in the linked list, with its coefficient and exponent.
2. **Evaluation**: To evaluate the polynomial at a specific value of \(x\):
   - Traverse the linked list, and for each node, compute the term's value using `coefficient * (x^exponent)`.
   - Sum all the computed values to get the final result.
3. **Example**: Evaluating the polynomial \(3x^2 + 5x + 2\) at \(x = 2\) would yield:
   - \(3 * (2^2) = 12\)
   - \(5 * (2^1) = 10\)
   - \(2 * (2^0) = 2\)
   - Final result: \(12 + 10 + 2 = 24\)

## Compilation and Execution

To compile and run the program, use the following commands:

```bash
g++ -o LinkedList main.cpp Node.cpp LinkedList.cpp
./LinkedList
