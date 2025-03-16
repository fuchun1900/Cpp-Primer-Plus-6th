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
    Pizza pizza;
    cout << "Enter the company name: ";
    cin.getline(pizza.company_name, 30);
    cout << "Enter the diameter of the pizza: ";
    cin >> pizza.diameter;
    cout << "Enter the weight of the pizza: ";
    cin >> pizza.weight;   

    cout << "Company name: " << pizza.company_name << endl;
    cout << "Diameter: " << pizza.diameter << endl;
    cout << "Weight: " << pizza.weight << endl;

    return 0;
}
