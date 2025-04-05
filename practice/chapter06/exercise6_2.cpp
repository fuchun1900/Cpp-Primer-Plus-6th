// Create by fuchun on 2025-04-05
#include <iostream>
#define SIZE 10
int main()
{
    using namespace std;
    double donation[SIZE];
    double sum = 0.0 ;
    int count = 0 , bigger = 0;
    cout << "Enter the numbers to calculate the average, enter 'q' to end: " << endl;
    for (size_t i = 0; i < SIZE && cin >> donation[i] ; i++)
    {
        sum+= donation[i];
        count++;
    }
    if (count == 0)
    {
        cout << "No numbers entered." << endl;
        return 0;
    }
    double average = sum/count;
    cout << "The average is: " << average<< endl;
    for (size_t i = 0; i < SIZE ; i++)
    {
        if (donation[i] > average)
            bigger++;
    }
    cout << bigger <<  " numbers are bigger than average  " << endl;

    return 0;
}
