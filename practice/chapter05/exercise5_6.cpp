// Create by fuchun on 2025-03-27
#include <iostream>
#include <cstring>

const  char years[12][20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int main()
{
    using namespace std;
    int sales[12] = {0};
    int total_sales = 0;
    for (size_t i = 0; i < 12; i++)
    {
        cout << "Enter the sales volume of " << years[i] << ":";
        cin >> sales[i];
        total_sales += sales[i];
    }
    cout << "The total sales volume of the year is " << total_sales << endl;

    for (size_t i = 0; i < 12; i++)
    {
       cout << "The sales volume of " << years[i] << " is " << sales[i] << endl;
    }
    
    return 0;
    
}
