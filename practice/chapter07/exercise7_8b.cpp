//arrobj.cpp -- functions with array objects
#include <iostream>
#include <string>
const int Seasons = 4;
const char * Snames[Seasons] =
    {"Spring", "Summer", "Fall", "Winter"};

struct Spend
{
    double money[Seasons];
};


void fill(double * pa);
void show(double * da);
int main()
{
    Spend expenses;
    fill(expenses.money);
    show(expenses.money);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(double * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa[i];
    }
}

void show(double * da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "Total: $" << total << '\n';
}
