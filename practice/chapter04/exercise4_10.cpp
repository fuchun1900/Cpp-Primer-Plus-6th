// Create by fuchun on 2025-03-16
#include <iostream>
#include <array>

const int times  = 3;
int main()
{
    using namespace std;
    array<double, times> result;
    double avg = 0.0;

    cout << "Enter the first time: ";
    cin >> result[0];
    cout << "Enter the second time: ";
    cin >> result[1];
    cout << "Enter the third time: ";
    cin >> result[2];

    avg = (result[0] + result[1] + result[2]) / times;
    cout << "The average of the three numbers is " << avg << endl;

    return 0;
}