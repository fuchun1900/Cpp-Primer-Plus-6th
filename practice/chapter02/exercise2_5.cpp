// Create by fuchun on 2025-02-23

#include <iostream>
using namespace std;

double celsiusToFahrenheit(double);

int main() {
    cout << "Please enter the Celsius value:  ";
    double celsius;
    cin >> celsius;
    cout << celsius << " degrees Celsius is " << celsiusToFahrenheit(celsius) << " degrees Fahrenheit." << endl;


    return 0;
}

double celsiusToFahrenheit(double celsius) {
    return 1.8 * celsius + 32.0;
}