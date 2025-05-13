#include <iostream>
#include <cctype>  // or ctype.h
#include "Stack.h"
int main()
{
    using namespace std;
    PaymentStack st; // create an empty stack
    char ch;
    double total = 0.0;
    cout << "Please enter A to add payment,\n"
        << "R to remove payment , or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')   
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
             case 'A':
             case 'a': 
                       Item bc;
                       cout << "Enter your name : ";
                       cin.getline(bc.fullname, 35);
                       cout << "Enter your payment : ";
                       cin >> bc.payment;
                       while (cin.get() != '\n')
                           continue;
                       if (st.isfull())
                           cout << "stack already full\n";
                       else
                           st.push(bc);
                           total += bc.payment;
                           std::cout << "Total payment: " <<total<< "\n";
                       break;
             case 'R':
             case 'r': if (st.isempty())
                           cout << "stack already empty\n";
                       else {
                           st.pop(bc);
                           total -= bc.payment;
                           cout << " You have taken: " << bc.fullname << "  $" <<bc.payment <<" .\n";
                           std::cout << "Total payment: " <<total << "\n";
                       }
                       break;
        }
        cout << "Please enter A to add payment,\n"
        << "R to remove payment , or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0; 
}