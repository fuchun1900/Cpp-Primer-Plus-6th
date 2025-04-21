//
// Created by fuchun on 4/21/25.
//
// Exercise 1: Write a template function that takes two arguments of the same type and returns the lesser of the two. Test it in a program that uses both int and double types.

#include <iostream>
void display(const char * str , int n = 1)
{
    if (n <= 0)
    {
        std::cout << "Loops end!" << std::endl;
        return;
    }
    std::cout << "Call funtion " << n << " times " << std::endl;
    std::cout << str << std::endl;
    display(str, n-1);

    return;
}
int main()
{
    display("Hello World!", 5);
    display("Hello World!");

    return 0;
}

