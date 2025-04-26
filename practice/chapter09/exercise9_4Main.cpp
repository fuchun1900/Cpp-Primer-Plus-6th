#include <iostream>
#include <cstring>
#include "SALES.h"

int main()
{
    using namespace SALES;
    Sales s1;
    double ar[QUARTERS] = { 100.0, 200.0, 300.0, 400.0 };
    setSales(s1, ar, 3);
    showSales(s1);

    Sales s2;
    setSales(s2);
    showSales(s2);


    return 0;
}