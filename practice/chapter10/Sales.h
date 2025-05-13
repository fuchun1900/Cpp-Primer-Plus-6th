#ifndef SALES_H
#define SALES_H
#include <iostream>

class SALES
{
private:
    static const int QUARTERS = 4;
    double sales[QUARTERS];
    double average;
    double max;
    double min;

public:
    SALES();
    SALES(const double ar[], int n);
    void showSales() const;
};

#endif