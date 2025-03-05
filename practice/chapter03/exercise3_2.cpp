// Create by fuchun on 2025-03-05
#include <iostream>

const int foot_to_inches = 12;
const double inches_to_meter = 0.0254;
const double pounds_to_kg = 2.2;

double BMI(double , double );

int main()
{
    using namespace std;
    double feet, inches, pounds;
    cout << "Please enter your height in feet and inches: ";
    cin >> feet >> inches;
    cout << "Please enter your weight in pounds: ";
    cin >> pounds; 

    double height = (feet * foot_to_inches + inches) * inches_to_meter;
    double wieght = pounds / pounds_to_kg;

    cout << "Your BMI is " << BMI(height, wieght) << endl;

    return 0;
}

double BMI(double height, double weight)
{
    return weight / (height * height);
}