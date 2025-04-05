// Create by fuchun on 2025-04-05
#include <iostream>

int main()
{
    using namespace std;

    const int SIZE = 100;
    struct Bop {
        char fullname[SIZE]; // real name
        char title[SIZE];    // job title
        char bopname[SIZE];  // secret BOP name
        int preference;         // 0 = fullname, 1 = title, 2 = bopname
    };

    const int MEMBERS = 5;
    Bop members[MEMBERS] = {
        {"Wimp Macho", "Junior Programmer", "Zork", 0},
        {"Rhea Putz", "Senior Programmer", "Cozmo", 1},
        {"Celia Laiter", "Junior Programmer", "Hawkeye", 2},
        {"Pat Hand", "Analyst Trainee", "Bingo", 1},
        {"Bingo Kosh", "Analyst Trainee", "Pat Hand", 0}
    };

    cout << "Benevolent order of Programmers report.\n"
         << "a. display by name\tb. display by title\n"
         << "c. display by bopname\td. display by preference\n"
         << "q. quit\n";

    char choice;
    cout << "Enter your choice: ";
    while ((choice = cin.get()) != 'q')
    {
        
        while (cin.get() != '\n') // discard rest of input line
            continue;
        switch (choice)
        {
        case 'a':
        case 'A':
            for (size_t i = 0; i < MEMBERS; i++)
            {
                cout << members[i].fullname << endl;
            }
            break;
        case 'b':
        case 'B':
            for (size_t i = 0; i < MEMBERS; i++)
            {
                cout << members[i].title << endl;
            }
            break;
        case 'c':
        case 'C':
            for (size_t i = 0; i < MEMBERS; i++)
            {
                cout << members[i].bopname << endl;
            }
            break;
        case 'd':
        case 'D':
            for (size_t i = 0; i < MEMBERS; i++)
            {
                if (members[i].preference == 0)
                    cout << members[i].fullname << endl;
                else if (members[i].preference == 1)
                    cout << members[i].title << endl;
                else
                    cout << members[i].bopname << endl;
            }
            break;
        case 'q':
        case 'Q':
            cout << "Bye!" << endl;
            break;
        default:
            cout << "Please enter a, b, c, d or q: " << endl;
            break;
        }
        cout << "Next choice: ";
    }
    return 0;
}

