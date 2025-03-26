// Create by fuchun on 2025-03-27
#include <iostream>
#include <cstring>
const int year = 3;
const int month = 12;
int main()
{
    using namespace std;
    const  char years[month][20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int sales[year][month] = {0};
    int total_sales_year[year] = {0};
    int total_sales = 0;

    for (size_t i = 0; i < year; i++)
    {
        for (size_t j = 0; j < month; j++)
        {
            cout << "Enter the sales volume of " << years[i] << " in year " << i + 1 << ":";
            cin >> sales[i][j];
            total_sales_year[i] += sales[i][j];
        }
    }
    for (size_t i = 0; i < year; i++)
    {
        total_sales += total_sales_year[i];
    }
    cout << "The total sales volume of " << year << " years " << " is " << total_sales << endl;
    
}