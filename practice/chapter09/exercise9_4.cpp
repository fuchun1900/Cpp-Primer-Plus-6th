# include <iostream>
# include <cstring>
# include "SALES.h"

void SALES::setSales(Sales & s, const double ar[], int n)
{
    if (n < QUARTERS)
    {
        for (size_t i = n; i < QUARTERS; i++)
            s.sales[i] = 0;
    }
    else
        n = QUARTERS;
    s.average = 0;
    s.max = ar[0];
    s.min = ar[0];
    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        s.sales[i] = ar[i];
        sum += ar[i];
        if (ar[i] > s.max)
            s.max = ar[i];
        if (ar[i] < s.min)
            s.min = ar[i];
    }
    s.average = sum / n;
}

void SALES::setSales(Sales & s)
{
    using std::cout;
    using std::cin;
    using std::endl;

    double ar[QUARTERS];
    for (size_t i = 0; i < QUARTERS; i++)
    {
        cout << "Enter sales for quarter " << i + 1 << ": ";
        cin >> ar[i];
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a number.\n";
            i--;
        }
    }
    setSales(s, ar, QUARTERS);
    cout << "Sales data entered successfully.\n";
    cin.ignore(100, '\n');
}

void SALES::showSales(const Sales & s)
{
    using std::cout;
    using std::endl;

    cout << "Sales data:\n";
    cout << "Sales: ";
    for (size_t i = 0; i < QUARTERS; i++)
        cout << s.sales[i] << " ";
    cout << endl;
    cout << "Average: " << s.average << endl;
    cout << "Max: " << s.max << endl;
    cout << "Min: " << s.min << endl;
}
