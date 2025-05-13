#include "list.h"
#include <iostream>

list::list() // create an empty stack
{
    top = 0;
}
bool list::isempty() const
{
    return top == 0;
}
bool list::isfull() const
{
    return top == MAX;
}
bool list::push(const Item & item) // add item to stack
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

void list::visit(void (*pf)(Item item)) const // apply function to items
{
    for (int i = 0; i < top; i++)
        pf(items[i]);
}
void show(Item item) // function to be used with visit()
{
    std::cout << item << " ";
}

int main()
{
    list mylist;
    Item item;
    std::cout << "Enter up to 10 numbers (q to stop): ";
    while (std::cin >> item)
    {
        if (!mylist.push(item)){
            std::cout << "List is full!\n";
            break;
        }
    }
    std::cout << "You entered: ";
    mylist.visit(show);
    std::cout << "\n";
    return 0;
}