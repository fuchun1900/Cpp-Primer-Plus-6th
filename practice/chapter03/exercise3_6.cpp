// Create by fuchun on 2025-03-05
#include <iostream>
const double gallon_to_liter = 3.78541;
const double mile_to_km = 1.60934;

int main() {
    using namespace std;
    double miles;
    double gallons;
    cout << "Enter the number of miles: ";
    cin >> miles;
    cout << "Enter the number of gallons: ";
    cin >> gallons;
    cout << "Your car's fuel consumption is " << miles / gallons << " miles per gallon." << endl;
    cout << "Your car's fuel consumption is " << (gallons * gallon_to_liter) / (miles * mile_to_km)  * 100
    << " liters per 100 kilometers." << endl;


    return 0;
    
}