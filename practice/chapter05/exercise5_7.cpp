// Create by fuchun on 2025-03-26  
#include <iostream>
#include <cstring>

using namespace std;
struct car_info
{
    char manufacturer[50];
    int date;
};

int main()
{
    int counts = 0;
    cout << "How many cars do you wish to catalog? ";
    cin >> counts;
    cin.get();
    car_info *cars = new car_info[counts];
    for (size_t i = 0; i < counts; i++)
    {
        cout <<"Car #" << i + 1 << ':' << endl;
        cout << "Please enter the make: ";
        cin.getline((cars + i)->manufacturer, 50);
        cout << "Please enter the year made: ";
        cin >> (cars + i)->date;
        cin.get();
    }
    cout << "here is your collection:" << endl;
    for (size_t i = 0; i < counts; i++)
    {
        cout << cars[i].date << '\n' << cars[i].manufacturer << endl;
    }
    delete [] cars;

    return 0;
    
}