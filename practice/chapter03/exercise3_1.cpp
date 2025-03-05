// Create by fuchun on 2025-03-05

#include <iostream>

int main()
{
    using namespace std;
    const int inches_per_foot = 12;
    cout << "Please enter your height in inches: ______\b\b\b\b\b\b";
    int height;
    cin >> height;

    cout << "Your height is " << height / inches_per_foot << " feet and " << height % inches_per_foot << " inches " << endl;

}