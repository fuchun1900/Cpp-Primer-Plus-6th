// Create by fuchun on 2025-04-05
#include <iostream>
#include <cctype>
#include <cstring>

int main()
{
    using namespace std;
    char word[100];
    cout << "Enter the words(q to quit): " << endl;
    int vowel = 0 , consonats = 0 , other = 0;
    while (cin >> word && strcmp(word, "q") != 0)
    {
        if (isalpha(word[0]))
        {
           switch (word[0])
           {
           case 'a':
           case 'A':
           case 'e':
           case 'E':
           case 'i':
           case 'I':
           case 'o':
           case 'O':
           case 'u':
           case 'U':
           vowel++;     
           break;
           
           default:
           consonats++;
           break;
           }
        }
        else
            other++;
    }
    cout << vowel << " words start with vowel." << endl;
    cout << consonats << " words start with consonats." << endl;
    cout << other << " words start with other characters." << endl;

    return 0;
}