//
// Created by Ahmed Elghazi on 4/27/23.
//
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

struct node{
    node* next;
    double coef;
    double expo;
};
int main()
{
    string full = "f(3.2) = 5.9x^11 + x^3 - 3x^10 + 10";
    //string full = "f(2.75) = 1.57x^47 - 2x^30 + x";
    //string full = "f(5) = 7x^2 - 9";
    node *head = nullptr;
    string evaluate, coeffecient, expon;
    double eval;
    int count = 0;
    bool neg = false;
    while(full != ""){
        neg = false;
        evaluate.clear();
        coeffecient.clear();
        expon.clear();
        term.clear();
        if(evaluate == "") // this does not go in the linkedlist
        {
            cout << "we are evaluating " << endl;
            evaluate = full.substr(full.find('('),full.find(')'));
            evaluate.erase(0,1);
            evaluate.erase(evaluate.end() - 1);
            eval = stod(evaluate);
            full = full.substr(full.find('=') + 2, full.size() - 1);
            cout << full << endl;
        }
        else // find the term, dynamic memory, make list, evaluate list
        {
            if(evaluate != "") // evaluate is 3.2
            {
                string negative = full.substr(0,1); // the first char of string full
                if(negative == "-")
                {
                    neg = true;
                }
                if(!isdigit(negative[0]))
                {
                    full = full.substr(full.find(' ') + 1);
                }
                cout << "FULL STRING AFTER SIGN:" << full << endl; // " x^3 - 3x^10 + 10"
            }
            string term;
            // this above line works when theres an X, does not work on constants
            if(full != "x") {
                if (full.find('x') != string::npos) {
                    term = full.substr(0, full.find(' ') + 1);
                } else {
                    term = full;
                    full.clear();
                }
                full = full.substr(full.find(' ') + 1);

                cout << "full string as of the first iteration:" << full << endl;
                if (term[0] != 'x') {
                    coeffecient = term.substr(0, term.find('x'));
                } else {
                    coeffecient = "1";
                }

                if (term.find('^') != string::npos) {
                    expon = term.substr(term.find('^') + 1, term.size());
                } else if (term.find('x') == string::npos) {
                    expon = '0';
                } else {
                    expon = "1";
                }
            }
            else
            {
                coeffecient = "1";
                expon = "1";
                full.clear();
            }
            if(head == nullptr)
            {
                head = new node;
                head->coef = stod(coeffecient);
                head->expo = stod(expon);
                head->next = nullptr;
            }
            else
            {
                node* mover = head;
                while (mover->next != nullptr)
                {
                    mover = mover->next;
                }
                node* A = new node;
                A->coef = stod(coeffecient);
                A->expo = stod(expon);
                A->next = nullptr;
                mover->next = A;
            }
        }
        cout <<'\n';
    }

    cout << "loops over, list: " << endl;
    while(head!= nullptr)
    {
        if(head->expo == '0')
        {
            cout << head->coef << endl;
        }

        else if(head->expo == '1')
        {
            cout << head->coef << "x" << endl;
        }

        else
        {
            cout << head->coef << "x^" << head->expo << endl;
        }
        head = head->next;
    }

    return 0;
}
