// forstr1.cpp -- using for with a string
#include <iostream>
#include <string>
#include <cstring>
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    //string word;
    char word[20];
    cin.getline(word, 20);
    for (int i = strlen(word); i >= 0; i--)
        cout << word[i];
    cout << "\nBye.\n";
    return 0; 
}
