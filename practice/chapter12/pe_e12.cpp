using namespace std;
#include <iostream>
#include "string2.h"

int main(){
    String s1(" and i am a C++ student."); // create a String object
    String s2 = "Please enter your name: "; // create a String object
    String s3;
    cout << s2; 
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n"; 
    s2 = s2 + s1; // concatenate two strings
    cout << s2 << "\n";
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A') << " 'A' characters in it.\n";
    s1 = "red";
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow();
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye.\n";
    return 0;
}