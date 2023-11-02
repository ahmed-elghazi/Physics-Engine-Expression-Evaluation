#ifndef PROJECT4_NODE_H
#define PROJECT4_NODE_H
class Node {
public:
    double coef;
    int exp;
    Node* next;

    // Default constructor
    Node();

    // Overloaded constructor
    Node(double coef, int exp);

    // Accessors and mutators
    double getCoef() const;
    void setCoef(double coef);
    int getExp() const;
    void setExp(int exp);
    Node* getNext() const;
    void setNext(Node* next);
};
#endif
