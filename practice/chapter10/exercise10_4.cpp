# include <iostream>
# include <cstring>
# include "Sales.h"

int main()
{
    using std::cout;
    using std::endl;

    double sales[] = { 15.2, 18, 17.6, 22.4 };
    SALES s1(sales, 5);
    s1.showSales();

    double sales2[] = { 5.0, 6.0 };
    SALES s2(sales2, 2);
    s2.showSales();

    SALES s3;
    s3.showSales();

    return 0;
}

SALES::SALES()  
{
    for (size_t i = 0; i < QUARTERS; i++)
        sales[i] = 0;
    average = 0;
    max = 0;
    min = 0;
}

SALES::SALES(const double ar[], int n)
{
    if (n < QUARTERS)
    {
        for (size_t i = n; i < QUARTERS; i++)
            sales[i] = 0;
    }
    else
        n = QUARTERS;
    average = 0;
    max = ar[0];
    min = ar[0];
    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sales[i] = ar[i];
        sum += ar[i];
        if (ar[i] > max)
            max = ar[i];
        if (ar[i] < min)
            min = ar[i];
    }
    average = sum / n;
}



void SALES::showSales() const
{
    using std::cout;
    using std::endl;

    cout << "Sales data:\n";
    cout << "Sales: ";
    for (size_t i = 0; i < QUARTERS; i++)
        cout <<"NO" << i + 1 << ": " << sales[i] << " ";
    cout << endl;
    cout << "Average: " << average << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}