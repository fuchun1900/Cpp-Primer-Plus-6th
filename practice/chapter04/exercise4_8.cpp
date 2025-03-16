// Create by fuchun on 2025-03-16
#include <iostream>

struct Pizza
{
    char company_name [30];
    double diameter;
    double weight;
};
int main()
{
    using namespace std;
    Pizza *ptr = new Pizza;

    cout << "Enter the diameter of the pizza: ";
    cin >> ptr->diameter;
    cout << "Enter the weight of the pizza: ";
    cin >> ptr->weight;
    cin.get(); // clear the newline character in the input buffer
    cout << "Enter the company name: ";
    cin.getline(ptr->company_name, 30);

    cout << "Company name: " << ptr->company_name << endl;
    cout << "Diameter: " << ptr->diameter << endl;
    cout << "Weight: " << ptr->weight << endl;

    delete ptr;

    return 0;
}