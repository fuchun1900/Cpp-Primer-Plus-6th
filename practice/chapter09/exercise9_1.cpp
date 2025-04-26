# include <iostream>
# include <cstring>
# include "golf.h"

void setgolf(golf &g, const char *name, int hc)
{
    std::strncpy(g.fullname, name, LEN);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    using std::cout;
    using std::cin;
    cin.getline(g.fullname, LEN);
    if (g.fullname[0] == '\0')
        return 0;
    int handicap;
    cout << "Enter handicap: ";
    while (!(cin >> handicap) || handicap < 0)
    {
        cin.clear(); // clear the error flag
        while (cin.get() != '\n') // discard invalid input
            continue;
        cout << "Please enter a positive integer: ";
    }
    cin.ignore(); // discard the newline character left in the input buffer
    setgolf(g, g.fullname, handicap);

    return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    using std::cout;
    using std::endl;
    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}

