#include <iostream>
#include <cctype>
#include <iterator>
using namespace std;

bool is_palindromic(const string &s)
{
    string::const_iterator left = s.begin();
    string::const_iterator right = s.end() - 1;
    while (left < right)
    {
        if (!isalpha(*left))
        {
            left++;
            continue;
        }
        if (!isalpha(*right))   
        {
            right--;
            continue;
        }
        if (tolower(*left) != tolower(*right))
            return false;
        left++;
        right--;
    }

    return true;
}

int main()
{
    string s;
    cout << "Enter a string (q to quit): ";
    while (getline(cin, s) && s != "q")
    {
        if (is_palindromic(s))
            cout << "\"" << s << "\" is a palindromic string.\n";
        else
            cout << "\"" << s << "\" is not a palindromic string.\n";
        cout << "Enter a string (q to quit): ";
    }
    cout << "Bye.\n";

    return 0;
}