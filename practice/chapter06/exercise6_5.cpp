// Create by fuchun on 2025-04-05
#include <iostream>

int main()
{
    using namespace std;

    long double tvarp = 0;
    double tax;
    cout << "Enter your salary: ";
    
    while (cin >> tvarp && tvarp > 0)
    {
        if (tvarp < 5000)
            tax  = 0;
        else if (tvarp <= 15000)
            tax = (tvarp - 5000) * 0.1;
        else if (tvarp <= 35000)
            tax = (tvarp - 15000) * 0.15 + (15000 - 5000) * 0.1;
        else if(tvarp > 35000)
            tax = (tvarp - 35000) * 0.2 + (35000 - 15000) * 0.15 + (15000 - 5000) * 0.1;
        
        
        cout << "Your tax is: " << tax << endl;
        cout << "Enter your salary: ";
    }
    
    return 0;
    
}