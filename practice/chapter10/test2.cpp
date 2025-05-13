#include "Person.h"
#include <iostream>

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwidddy", "Sam");
    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();

    return 0;
}