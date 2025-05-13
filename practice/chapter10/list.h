#ifndef LIST_H_
#define LIST_H_
typedef unsigned long Item;
#include <iostream>
void show(Item item);    // function prototype

class list
{
private:
    static const int MAX = 10;    // constant specific to class
    Item items[MAX];    // holds stack items
    int top;            // index for top stack item
public:
    list();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stac
    void visit(void (*pf)(Item item)) const; // apply function to items
};

#endif