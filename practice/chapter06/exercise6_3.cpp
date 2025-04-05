// Create by fuchun on 2025-04-05
#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter one of the following choices:\n"
             << "c) carnivore\tp) pianist\n"
             << "t) tree\t\tg) game\n";
    ch = cin.get();
    switch (ch)
    {
    case 'c':
    case 'C':
        cout << "A maple is a carnivore.\n";
        break;
    case 'p':
    case 'P':
        cout << "A maple is a pianist.\n";
        break;
    case 't':
    case 'T':
        cout << "A maple is a tree.\n";
        break;
    case 'g':
    case 'G':
        cout << "A maple is a game.\n";
        break;
    
    default:
        cout << "Please enter a c, p, t or g.\n";
        while (cin.get() != '\n')
            continue; // discard rest of input line
        break;
    }

    return 0;
    
}
