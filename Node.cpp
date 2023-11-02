#include "Node.h"

// Default constructor
Node::Node() : coef(0), exp(0), next(nullptr) {}

// Overloaded constructor
Node::Node(double coef, int exp) : coef(coef), exp(exp), next(nullptr) {}

// Accessors and mutators
double Node::getCoef() const {
    return coef;
}

void Node::setCoef(double coef) {
    this->coef = coef;
}

int Node::getExp() const {
    return exp;
}

void Node::setExp(int exp) {
    this->exp = exp;
}

// Set next node
void Node::setNext(Node* next) {
    this->next = next;
}

