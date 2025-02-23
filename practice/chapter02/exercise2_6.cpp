// Create by fuchun on 2021-07-19

#include <iostream>

double lightYearsToAstronomicalUnits(double);

int main() {
    using namespace std;
    
    cout << "Enter the number of light years: ";
    double lightYears;
    cin >> lightYears;
    cout << lightYears << " light years = " << lightYearsToAstronomicalUnits(lightYears) << " astronomical units." << endl;

    
    return 0;
}

double lightYearsToAstronomicalUnits(double lightYears) {
    return lightYears * 63240;
}