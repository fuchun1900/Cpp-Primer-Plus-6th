#ifndef STACK_H_
#define STACK_H_

typedef struct Stack
{
    char fullname[35];
    double payment;
} Item;

class PaymentStack
{
private:
    static const int MAX = 10;    // constant specific to class
    Item items[MAX];    // holds stack items
    int top;            // index for top stack item;
public:      
    PaymentStack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
};
#endif