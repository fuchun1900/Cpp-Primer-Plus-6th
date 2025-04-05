// Create by fuchun on 2025-04-05
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    ifstream fin;
    char filename[100];
    cout << "Enter the file name: ";
    cin.getline(filename, 100);
    fin.open(filename);
    if (!fin)
    {
        cout << "Could not open the file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    struct donation
    {
        char fullname[50];
        double amount;
    };
    //cout << "Please enter the number of donations: ";
    int num;
    fin >> num;
    donation *donations = new donation[num];
    fin.get(); // discard the newline character

    for (int i = 0; fin.good() && i < num; i++)
    {
        //cout << "Please enter the donation name: ";
        fin.getline(donations[i].fullname, 50);
        //cout << "Please enter the donation amount: ";
        fin >> donations[i].amount;
        fin.get(); // discard the newline character
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
    fin.close();

    return 0;

}