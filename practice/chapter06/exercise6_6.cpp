// Create by fuchun on 2025-04-05
#include <iostream>

int main()
{
    using namespace std;

    struct donation
    {
        char fullname[50];
        double amount;
    };
    cout << "Please enter the number of donations: ";
    int num;
    cin >> num;
    donation *donations = new donation[num];
    cin.get(); // discard the newline character

    for (size_t i = 0; i < num; i++)
    {
        cout << "Please enter the donation name: ";
        cin.getline(donations[i].fullname, 50);
        cout << "Please enter the donation amount: ";
        cin >> donations[i].amount;
        cin.get(); // discard the newline character
    }
    int empty = 0;
    int * GP = new int[num];
    
    for (size_t i = 0; i < num; i++)
    {
        if (donations[i].amount > 10000)
            GP[i] = 1;
    }

    cout << "The Grand Patrons are: " << endl;
    for (size_t i = 0; i < num; i++)
    {
        if (GP[i] == 1)
        {
            cout << donations[i].fullname << endl;
            empty++;
        }
    }
    if (!empty)
        cout << "No Grand Patrons." << endl;
    empty = 0;
    cout << "The Patrons are: " << endl;
    for (size_t i = 0; i < num; i++)
    {
        if (GP[i] == 0)
        {
            cout << donations[i].fullname << endl;
            empty++;
        }
    }
    if (!empty)
        cout << "No Patrons." << endl;

    delete[] donations;
    delete[] GP;

    return 0;

}

