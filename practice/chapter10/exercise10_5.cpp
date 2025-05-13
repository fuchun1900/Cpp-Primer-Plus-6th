#include "Stack.h"
#include <iostream>
PaymentStack::PaymentStack()    // create an empty stack
{
    top = 0;
}

bool PaymentStack::isempty() const
{
    return top == 0;
}

bool PaymentStack::isfull() const
{
    return top == MAX;
}

bool PaymentStack::push(const Item & item) 
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool PaymentStack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        items[top] = {};
        return true;
    }
    else
        return false; 
}