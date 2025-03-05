// Create by fuchun on 2025-03-05
#include <iostream>

const double gallon_to_liter = 3.87541;
const double km_to_miles = 0.621371;

int main() {
    using namespace std;

    double consumption;
    cout << "Enter the fuel consumption in liters per 100 kilometers: ";
    cin >> consumption;
    
    cout << "Your car's fuel consumption  (Euro style) is " << consumption << " liters per 100 kilometers." << endl;
    cout << "Your car's fuel consumption (US style) is " <<  (100 * km_to_miles) / (consumption / gallon_to_liter) 
    << " miles per gallon." << endl;
 

    return 0;
}