//
// Created by fuchun on 2025/04/12.

# include <iostream>
using namespace std;

float harmonic_mean(float a, float b);

int main()
{
    float a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    while (a * b != 0.0)
    {
        cout << "Harmonic mean of " << a << " and " << b << " is "
             << harmonic_mean(a, b) << endl;
        cout << "Enter two numbers: ";
        cin >> a >> b;
    } 
}

float harmonic_mean(float a, float b)
{
    return 2.0 * a * b / (a + b);
}
// The program calculates the harmonic mean of two numbers.



