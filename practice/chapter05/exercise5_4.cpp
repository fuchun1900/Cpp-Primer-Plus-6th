// Create by fuchun on 2025-03-27
#include <iostream>
using namespace std;
int main()
{
    int years = 0;
    double Daphne = 100.0;
    double Cleo = 100.0;
    while (Daphne >= Cleo)
    {
        Daphne += 100 * 0.1;
        Cleo += Cleo * 0.05;
        years++;
    }

    cout << "After " << years << " years, Cleo's investment exceeds Daphne's investment." << endl;
    cout << "Daphne's investment is " << Daphne << ", Cleo's investment is " << Cleo << endl;
    
    
    return 0;
}

