//
// Created by fuchun on 2025/4/12.
//
#include <iostream>
#include <cmath>

long double probability(unsigned numbers, unsigned picks);

int main()
{
    unsigned total, chioces;
    long double result = 1;  // here come some local variables
    std::cout << "Enter the total number of choices on the game card and\n"
                 "the number of picks allowed:\n";
    for (size_t i = 0; i < 2; i++)
    {
        std::cout <<"Please enter the " << i + 1 << " range of numbers: ";
        std::cin >> total >> chioces;
        if (total < chioces)
        {
            std::cout << "The number of choices must be greater than the number of picks.\n";
            std::cout << "Please enter again.\n";
            (i == 0)? i:i--;
            continue;
        }       
        result *= probability(total, chioces);
    }
    std::cout << "You have one chance in " << result << " of winning.\n";
    std::cout << "bye\n";
}
// the following function calculates the probability of picking picks

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;  // here come some local variables

    for (long double n = numbers, p = picks; p > 0; n--, p--)
        result = result * (n / p);
    return result;
}
