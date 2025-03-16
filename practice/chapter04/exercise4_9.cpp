// Create by fuchun on 2025-03-16

#include <iostream>
using namespace std;

struct CandyBar
{
    char brand[20];
    double weight;
    int calories;
};

int main()
{
    CandyBar *str = new CandyBar[3];

    for (size_t i = 0; i < 3; i++)
    {
       cout << "Enter brand name of candy bar: ";
       cin.getline(str[i].brand, 20);
       cout << "Enter weight of the candy bar: ";
       cin >> (str + i)->weight;
       cout << "Enter calories (an integer value) in the candy bar: ";
       cin >> (*(str + i)).calories;
       cin.get(); // clear the newline character in the input buffer
    }

    for (size_t i = 0; i < 3; i++)
    {
        cout << "Brand: " << str[i].brand << endl;
        cout << "Weight: " << str[i].weight << endl;
        cout << "Calories: " << str[i].calories << endl;
    }

    delete [] str;

    return 0;
    
}

