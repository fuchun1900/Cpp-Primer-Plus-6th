// Create by fuchun on 2025-04-05
#include <iostream>
#include <cctype>

int main()
{
    using namespace std;
    char ch;
    cout << "Enter the characters,except digit, to count the number of characters: " << endl;
    while ((ch = cin.get()) != '@')
    {
        if (isdigit(ch))
        {
            continue;
        }
        if (isupper(ch))
        {
            ch = tolower(ch);

        }
        else if (islower(ch))
        {
            ch = toupper(ch);
        }
        cout << ch;
    }

    return 0;
}

